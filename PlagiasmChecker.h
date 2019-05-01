//
// Created by anton on 01.05.19.
//

#ifndef COOLSTEAL_PLAGIASMCHECKER_H
#define COOLSTEAL_PLAGIASMCHECKER_H

#include "models/PlagiasmResult.h"
#include "models/Program.h"
class PlagiasmChecker {
 public:
  PlagiasmResult checkProgramWithDB(Program &program);
 private:
   PlagiasmLibary plagiasmLibary;
   PlagiasmLexer lex;
   DBmanager DBmanager;
};

#endif //COOLSTEAL_PLAGIASMCHECKER_H
