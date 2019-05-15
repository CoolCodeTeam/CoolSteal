#ifndef COOLSTEAL_DBCLIENT_H
#define COOLSTEAL_DBCLIENT_H

#include "postgres-connection.h"
#include "postgres-exceptions.h"


#include "../models/Program.h"
class DBManager {
 public:
  DBManager();
  bool addProgram(const Program &program);
  Program getProgram(long id);
  int getNewId();

 private:
  bool get_conn = false;
  db::postgres::Connection conn;
  std::string vector_to_postgres(const std::vector <std::string> &V);
  std::string shingles_to_postgres(const std::set <std::string> &S);
  std::set<std::string> postgres_to_shingles(const std::string &str);
};

#endif //COOLSTEAL_DBCLIENT_H
