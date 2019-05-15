#include "DBManager.h"
#include <algorithm>
#include <sstream>
#include <iterator>
#include <limits>

using db::postgres::Connection;

DBManager::DBManager() {

  try {
    conn.connect("postgresql://cooler:cool@localhost/cooldb");

    conn.execute(R"SQL(

      CREATE TABLE IF NOT EXISTS programs (
        id              SERIAL         NOT NULL,

        name            VARCHAR(128)    NOT NULL,
        source_code     TEXT                    ,
        normilize_code  TEXT                    ,
        token_set       TEXT                    ,
        shingle_set     VARCHAR(128)[]          ,

        owner_id        SERIAL          NOT NULL,
        date            DATE                    ,
        lang            VARCHAR(32)     NOT NULL,

        PRIMARY KEY (id)
      );

    )SQL");

    std::cout << "Table created." << std::endl;

    get_conn = true;
  }
  catch (db::postgres::ConnectionException e) {
    std::cerr << "Cannot connect...";
  }
  catch (db::postgres::ExecutionException e) {
    std::cerr << e.what();
  }
}

int DBManager::getNewId() {        // 0 rows => id = 0

  if(!get_conn)
    return -1;

  auto &max = conn.execute(R"SQL(
    SELECT MAX(id) as max FROM programs
    )SQL");

  return max.as<int>(0);
}

bool DBManager::addProgram(const Program &program) {
  if(!get_conn)
    return false;

  int id = getNewId();

  conn.execute(R"SQL(
          INSERT INTO programs VALUES
          ($1, $2, $3, $4,
           $5, $6::varchar(128)[], $7, '2006-06-26', $8)
)SQL", id, program.getName(), program.getSourseCode(), program.getNormalizeCode(),
       program.getTokenSet(), shingles_to_postgres(program.getShingleSet()), program.getOwnerId(), program.getLang());
}

Program DBManager::getProgram(long id) {
  Program p;

  if(!get_conn){
    p.setId(-1);
    return p;
  }

  auto &program = conn.execute(R"SQL(
      SELECT * FROM programs
               WHERE id = $1
    )SQL", id);

  p.setId(id);
  p.setName(program.as<std::string>(1));
  p.setSourseCode(program.as<std::string>(2));
  p.setNormalizeCode(program.as<std::string>(3));
  p.setTokenSet(program.as<std::string>(4));
  p.setShingleSet(postgres_to_shingles(program.as<std::string>(5)));
  p.setOwnerId(program.as<long>(6));
  //TODO: WHAT ABOUT DATE?
  p.setLang(program.as<std::string>(8));

  return p;
}




std::string DBManager::vector_to_postgres(const std::vector<std::string> &V) {
  std::ostringstream oss;

  oss << "{";
  if (!V.empty()) {
    oss << "\"";
    std::copy(V.begin(), V.end() - 1,
              std::ostream_iterator<std::string>(oss, "\",\""));

    oss << V.back() << "\"";
  }
  oss << "}";
  return oss.str();
}

std::string DBManager::shingles_to_postgres(const std::set<std::string> &S) {
  std::ostringstream oss;

  oss << "{";
  if (!S.empty()) {
    oss << "\"";
    std::copy(S.begin(), S.end(),
              std::ostream_iterator<std::string>(oss, "\",\""));
  }
  std::string t = oss.str();

  t[t.size() - 2] = '}';
  t.pop_back();
  return t;
}

std::set<std::string> DBManager::postgres_to_shingles(const std::string &str) {
  int i = 1, j = 2;
  std::set<std::string> S;

  while(str[i] != '}'){
    if(str[i] == '"'){
      if(i > j){
        S.insert(str.substr(j, i));
        j = i + 3;
      }
    }
    i++;
  }

  return S;
}



/*
int StartDataBase() {
  Connection conn;
  try {
    conn.connect("postgresql://cooler:cool@localhost/cooldb");

    conn.execute(R"SQL(

      CREATE TABLE IF NOT EXISTS programs (
        id              SERIAL         NOT NULL,

        name            VARCHAR(128)    NOT NULL,
        source_code     TEXT                    ,
        normilize_code  TEXT                    ,
        token_set       TEXT                    ,
        shingle_set     VARCHAR(128)[]          ,

        owner_id        SERIAL          NOT NULL,
        date            DATE            NOT NULL,
        lang            VARCHAR(32)     NOT NULL,

        PRIMARY KEY (id)
      );

    )SQL");

    std::cout << "Table created." << std::endl;

    set<string> S = {"a", "b"};

    std::ostringstream oss;

    oss << "{";
    if (!S.empty()) {
      oss << "\"";
      std::copy(S.begin(), S.end(),
                std::ostream_iterator<std::string>(oss, "\",\""));
      // FIXME

    }
    string t = oss.str();
    t[t.size()-2] = '}';
    t.pop_back();




        string code = "#include <stdio.h> #include <stdlib.h> int main() { }";

        conn.execute(R"SQL(
          INSERT INTO programs VALUES
          (1, 'first', $1, '#include <stdio.h> #include <stdlib.h> int main() { }',
           '{"a", "b"}', $2::varchar(128)[], 228, '2006-06-26', 'cpp')
)SQL", code, t);


    auto &max = conn.execute(R"SQL(
    SELECT MAX(id) as max FROM programs
    )SQL");

    cout << max.as<int>(0) << endl;

    return 0;
  }
  catch (ConnectionException e) {
    std::cerr << "Cannot connect...";
  }
  catch (ExecutionException e) {
    std::cerr << e.what();
  }

  return -1;
}
 */