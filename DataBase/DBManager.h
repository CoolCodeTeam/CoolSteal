//
// Created by anton on 08.05.19.
//

#ifndef COOLSTEAL_DBCLIENT_H
#define COOLSTEAL_DBCLIENT_H

#include "../models/Program.h"
class DBManager {
 public:
  void addProgram(const Program &program);
  Program getProgram(unsigned int id);
  int getNewId();
};

#endif //COOLSTEAL_DBCLIENT_H
