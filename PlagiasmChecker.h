//
// Created by anton on 01.05.19.
//

#ifndef COOLSTEAL_PLAGIASMCHECKER_H
#define COOLSTEAL_PLAGIASMCHECKER_H

#include "models/PlagiasmResult.h"
#include "models/Program.h"
#include "methods/CheckLibary.h"
#include "Normalizator/Normalizator.h"
class PlagiasmChecker {
 public:
  PlagiasmResult checkProgramWithDB(Program &program);
  PlagiasmResult comparePrograms(Program &firstProgram, Program &secondProgram);
  CheckLibary checkLibary;
  Normalizator normalizator;
//   PlagiasmLexer lex;
//   DBmanager DBmanager;
};

#endif //COOLSTEAL_PLAGIASMCHECKER_H
