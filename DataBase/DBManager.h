#ifndef COOLSTEAL_DBCLIENT_H
#define COOLSTEAL_DBCLIENT_H

#include "postgres-connection.h"
#include "postgres-exceptions.h"


#include "../models/Program.h"
class DBManager {
 public:
  DBManager();
  void addProgram(const Program &program);
  Program getProgram(unsigned int id);
  int getNewId();

 private:
  db::postgres::Connection conn;
  std::string vector_to_postgres(const std::vector <std::string> &V);
  std::string shingles_to_postgres(const std::set <std::string> &S);
};

#endif //COOLSTEAL_DBCLIENT_H
