#include "DBManager.h"
#include <algorithm>
#include <sstream>
#include <iterator>

using db::postgres::Connection;

DBManager::DBManager() {
  conn.connect("postgresql://cooler:cool@localhost/cooldb");
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
    // FIXME

  }
  std::string t = oss.str();

  t[t.size() - 2] = '}';
  t.pop_back();
  return t;
}

int DBManager::getNewId() {        // 0 rows => id = 0

  auto &max = conn.execute(R"SQL(
    SELECT MAX(id) as max FROM programs
    )SQL");

  return max.as<int>(0);
}

void DBManager::addProgram(const Program &program) {
  conn.connect("postgresql://cooler:cool@localhost/cooldb");

  int id = getNewId();

  conn.execute(R"SQL(
          INSERT INTO programs VALUES
          ($1, $2, $3, $4,
           $5, $6::varchar(128)[], $7, '2006-06-26', $8)
)SQL", id, program.getName(), program.getSourseCode(), program.getNormalizeCode(),
       program.getTokenSet(), shingles_to_postgres(program.getShingleSet()), program.getOwnerId(), program.getLang());
}

