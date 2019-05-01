//
// Created by anton on 01.05.19.
//
#include "ShingleChecker.h"
#ifndef COOLSTEAL_CHECKLIBARY_H
#define COOLSTEAL_CHECKLIBARY_H

#include "CheckLibaryInterface.h"
class CheckLibary: public CheckLibaryInterface {
 public:
  PlagiasmResult getSimilaity(Program &originalProgram, const Program &comparedProgram) override ;
  PlagiasmResult getSimilaity(Program &originalProgram, Program &comparedProgram) override ;
  int getShingleResult(Program &originalProgram, const Program &comparedProgram) override;
  int getShingleResult(Program &originalProgram, Program &comparedProgram) override;
  int getLevenstainResult(Program &originalProgram, const Program &comparedProgram) override;
  int getOperatorPlagiasmResult(Program &originalProgram, const Program &comparedProgram) override;
 private:
  ShingleChecker shingleChecker;
};

#endif //COOLSTEAL_CHECKLIBARY_H
