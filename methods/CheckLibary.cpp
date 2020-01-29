//
// Created by anton on 01.05.19.
//

#include <thread>
#include <future>
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
  //MultiThread is here!!
  auto shingleFutureResult(std::async([this](Program &originalProgram,
                                             Program &comparedProgram){
    return getShingleResult(originalProgram,comparedProgram);
    },
    std::ref(originalProgram),std::ref(comparedProgram)));
  auto levenstainFutureResult(std::async([this](Program &originalProgram,
                                             Program &comparedProgram){
                                        return getLevenstainResult(originalProgram,comparedProgram);
                                      },
                                      std::ref(originalProgram),std::ref(comparedProgram)));
  auto operatorFutureResult(std::async([this](Program &originalProgram,
                                             Program &comparedProgram){
                                        return getOperatorPlagiasmResult(originalProgram,comparedProgram);
                                      },
                                      std::ref(originalProgram),std::ref(comparedProgram)));
  auto opSeqFutureResult(std::async([this](Program &originalProgram,
                                             Program &comparedProgram){
                                        return getOpSequencePlagiasmResult(originalProgram,comparedProgram);
                                      },
                                      std::ref(originalProgram),std::ref(comparedProgram)));
  int shingleResult = shingleFutureResult.get();
  int levenstainResult = levenstainFutureResult.get();
  int operatorResult = operatorFutureResult.get();
  int opSeqResult = opSeqFutureResult.get();
  return PlagiasmResult(shingleResult,levenstainResult,operatorResult,opSeqResult);
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
