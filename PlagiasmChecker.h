//
// Created by anton on 01.05.19.
//

#ifndef COOLSTEAL_PLAGIASMCHECKER_H
#define COOLSTEAL_PLAGIASMCHECKER_H

#include "models/PlagiasmResult.h"
#include "models/Program.h"
#include "methods/CheckLibary.h"
#include "Normalizator/Normalizator.h"
#include "lexUtils/LexerCpp.h"
#include "DataBase/DBManager.h"
class PlagiasmChecker {
 public:
  PlagiasmResult checkProgramWithDB(Program &program);
  PlagiasmResult comparePrograms(Program &firstProgram, Program &secondProgram);
 private:
  CheckLibary checkLibary;
  Normalizator normalizator;
  LexerCpp lex;
//   PlagiasmLexer lex;
//   DBmanager DBmanager;
};

#endif //COOLSTEAL_PLAGIASMCHECKER_H
