//
// Created by anton on 01.05.19.
//

#include "PlagiasmChecker.h"
#include "DataBase/DBManager.h"
PlagiasmResult PlagiasmChecker::checkProgramWithDB(Program &program) {

  DBManager dbManager;

  PlagiasmResult maxResult(program.getId(),0,0,0,0,0);
  program.setNormalizeCode(normalizator.normalize(program));
  program.setTokenSet(lex.getTokens(program));
  program.setOperatorSet(lex.getOpSet(program));

  program.setId(dbManager.getNewId());
  for (int i =1;i<program.getId();i++){
    Program curProgram = dbManager.getProgram(i);
    if (curProgram.getOperatorSet().size()==0){
      curProgram.setOperatorSet(lex.getOpSet(curProgram));
    }
    PlagiasmResult curResult = checkLibary.getSimilaity(program, curProgram);
    curResult.setId(program.getId());
    curResult.setMostSimilarProgrammId(i);
    if (curResult.getGeneralSimilarity()>maxResult.getGeneralSimilarity()){
      maxResult=curResult;//TODO: =constructor
    }
  }
  dbManager.addProgram(program);

  return maxResult;

}
PlagiasmResult PlagiasmChecker::comparePrograms(Program &firstProgram, Program &secondProgram) {
  //return plagiasmLibary.getSimilarity(firstProgram,secondProgram);

  firstProgram.setNormalizeCode(normalizator.normalize(firstProgram));
  secondProgram.setNormalizeCode(normalizator.normalize(secondProgram));
  firstProgram.setTokenSet(lex.getTokens(firstProgram));
  secondProgram.setTokenSet(lex.getTokens(secondProgram));// Временно
  firstProgram.setOperatorSet(lex.getOpSet(firstProgram));
  secondProgram.setOperatorSet(lex.getOpSet(secondProgram));
  PlagiasmResult result = checkLibary.getSimilaity(firstProgram,secondProgram);
  return result;
}
