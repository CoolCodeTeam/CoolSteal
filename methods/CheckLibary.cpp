//
// Created by anton on 01.05.19.
//

#include "CheckLibary.h"
PlagiasmResult CheckLibary::getSimilaity(Program &originalProgram, const Program &comparedProgram) {
  return PlagiasmResult(shingleChecker.check(originalProgram,comparedProgram),0,0);
}

PlagiasmResult CheckLibary::getSimilaity(Program &originalProgram, Program &comparedProgram) {
  return PlagiasmResult(shingleChecker.check(originalProgram,comparedProgram),0,0);
}
int CheckLibary::getShingleResult(Program &originalProgram, const Program &comparedProgram) {
  return 0;
}
int CheckLibary::getShingleResult(Program &originalProgram, Program &comparedProgram) {
  return shingleChecker.check(originalProgram,comparedProgram);
}

int CheckLibary::getLevenstainResult(Program &originalProgram, const Program &comparedProgram) {
  return 0;
}
int CheckLibary::getOperatorPlagiasmResult(Program &originalProgram, const Program &comparedProgram) {
  return 0;
}

