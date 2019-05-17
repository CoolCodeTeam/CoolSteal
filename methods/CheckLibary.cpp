//
// Created by anton on 01.05.19.
//

#include "CheckLibary.h"
PlagiasmResult CheckLibary::getSimilaity(Program &originalProgram,
                                         const Program &comparedProgram) {
  return PlagiasmResult(
      shingleChecker.check(originalProgram, comparedProgram),
      levenstainChecker.check(originalProgram, comparedProgram),
      operatorPlagiasmChecker.check(originalProgram, comparedProgram),
      opSequencePlagiasmChecker.check(originalProgram, comparedProgram));
}

PlagiasmResult CheckLibary::getSimilaity(Program &originalProgram,
                                         Program &comparedProgram) {
  return PlagiasmResult(
      shingleChecker.check(originalProgram, comparedProgram),
      levenstainChecker.check(originalProgram, comparedProgram),
      operatorPlagiasmChecker.check(originalProgram, comparedProgram),
      opSequencePlagiasmChecker.check(originalProgram, comparedProgram));
}
int CheckLibary::getShingleResult(Program &originalProgram,
                                  const Program &comparedProgram) {
  return 0;
}
int CheckLibary::getShingleResult(Program &originalProgram,
                                  Program &comparedProgram) {
  return shingleChecker.check(originalProgram, comparedProgram);
}

int CheckLibary::getLevenstainResult(Program &originalProgram,
                                     const Program &comparedProgram) {
  return levenstainChecker.check(originalProgram, comparedProgram);
}
int CheckLibary::getOperatorPlagiasmResult(Program &originalProgram,
                                           Program &comparedProgram) {
  return operatorPlagiasmChecker.check(originalProgram, comparedProgram);
}
int CheckLibary::getOpSequencePlagiasmResult(Program &originalProgram,
                                             Program &comparedProgram) {
  return opSequencePlagiasmChecker.check(originalProgram, comparedProgram);
}
