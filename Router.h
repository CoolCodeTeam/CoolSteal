//
// Created by anton on 26.04.19.
//

#ifndef COOLSTEAL_ROUTER_H
#define COOLSTEAL_ROUTER_H

#include "models/Program.h"
#include "models/PlagiasmResult.h"
#include "PlagiasmChecker.h"
class Router {
 public:
  Router();
  PlagiasmResult checkProgram(Program &program);
  int getNewId();
  PlagiasmResult comparePrograms(Program &firstProgram, Program &secondProgram);
 private:
   PlagiasmChecker checker;
};


#endif //COOLSTEAL_ROUTER_H