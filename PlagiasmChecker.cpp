//
// Created by anton on 01.05.19.
//

#include "PlagiasmChecker.h"
PlagiasmResult PlagiasmChecker::checkProgramWithDB(Program &program) {


//  DBmanager.addProgram(program);
//  PlagiasmResult maxResult(program.getId(),0,0,0,0);
//  program.setTokenSet(Lex(program));
//  for (int i =0;i<program.getId();i++){
//    Program curProgram = DBmanager.getProgram(i);
//    if (curProgram.getOwnerId()!=program.getOwnerId()) {
//      PlagiasmResult curResult = plagiasmLibary.getSimilarity(program, curProgram);
//      curResult.setId(program.getId());
//      curResult.setMostSimilarProgrammId(i);
//      if (curResult.getGeneralSimilarity()>maxResult.getGeneralSimilarity()){
//        maxResult=curResult;//TODO: =constructor
//      }
//    }
//  }
//
//  return maxResult;
  return PlagiasmResult(0,0,0,0,0);
}
PlagiasmResult PlagiasmChecker::comparePrograms(Program &firstProgram, Program &secondProgram) {
  //return plagiasmLibary.getSimilarity(firstProgram,secondProgram);
  std::vector<char> testTokenSetFirst(firstProgram.getSourseCode().begin(), firstProgram.getSourseCode().end());
  std::vector<char> testTokenSetSecond(secondProgram.getSourseCode().begin(), secondProgram.getSourseCode().end());
  firstProgram.setTokenSet(testTokenSetFirst);
  secondProgram.setTokenSet(testTokenSetSecond);
  PlagiasmResult result = checkLibary.getSimilaity(firstProgram,secondProgram);
  return result;
}
