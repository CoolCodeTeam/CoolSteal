#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <iostream>
#include <gtest/gtest.h>
#include "CoolStealServerApp.h"

#include "postgres-connection.h"
#include "postgres-exceptions.h"

using namespace db::postgres;

int StartDataBase();

int main(int argc, char **argv) {
  StartDataBase();

  //CoolStealServerApp app;
  //testing::InitGoogleTest(&argc, argv);
  //RUN_ALL_TESTS();
  //return app.run(argc, argv);

}

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