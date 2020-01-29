//
// Created by anton on 01.05.19.
//

#include "PlagiasmChecker.h"
#include "DataBase/DBManager.h"
#include <thread>
#include <future>
PlagiasmResult PlagiasmChecker::checkProgramWithDB(Program &program) {
  DBManager dbManager;
  auto futureProgramNormalizeCode(std::async([this](Program &Program){
    return normalizator.normalize(Program);
  },std::ref(program)));
  auto futureProgramTokenSet(std::async([this](Program &program){
    return lex.getTokens(program);
  },std::ref(program)));
  auto futureProgramOperatorSet(std::async([this](Program &program){
    return lex.getOpSet(program);
  },std::ref(program)));

  PlagiasmResult maxResult(program.getId(),0,0,0,0,0);
  program.setNormalizeCode(futureProgramNormalizeCode.get());
  program.setTokenSet(futureProgramTokenSet.get());
  program.setOperatorSet(futureProgramOperatorSet.get());

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
      maxResult=curResult;
    }
  }
  dbManager.addProgram(program);

  return maxResult;

  DBManager dbManager;

  PlagiasmResult maxResult(program.getId(),0,0,0,0);
  program.setNormalizeCode(normalizator.normalize(program));
  program.setTokenSet(lex.getTokens(program));

  program.setId(dbManager.getNewId());
  for (int i =1;i<program.getId();i++){
    Program curProgram = dbManager.getProgram(i);

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
  auto futureFirstProgramNormalizeCode(std::async([this](Program &firstProgram){
    return normalizator.normalize(firstProgram);
  },std::ref(firstProgram)));
  auto futureSecondProgramNormalizeCode(std::async([this](Program &secondProgram){
    return normalizator.normalize(secondProgram);
  },std::ref(secondProgram)));
  auto futureFirstProgramTokenSet(std::async([this](Program &firstProgram){
    return lex.getTokens(firstProgram);
  },std::ref(firstProgram)));
  auto futureSecondProgramTokenSet(std::async([this](Program &secondProgram){
    return lex.getTokens(secondProgram);
  },std::ref(secondProgram)));
  auto futureFirstProgramOperatorSet(std::async([this](Program &firstProgram){
    return lex.getOpSet(firstProgram);
  },std::ref(firstProgram)));
  auto futureSecondProgramOperatorSet(std::async([this](Program &secondProgram){
    return lex.getOpSet(secondProgram);
  },std::ref(secondProgram)));

  firstProgram.setNormalizeCode(futureFirstProgramNormalizeCode.get());
  secondProgram.setNormalizeCode(futureSecondProgramNormalizeCode.get());
  firstProgram.setTokenSet(futureFirstProgramTokenSet.get());
  secondProgram.setTokenSet(futureSecondProgramTokenSet.get());
  firstProgram.setOperatorSet(futureFirstProgramOperatorSet.get());
  secondProgram.setOperatorSet(futureSecondProgramOperatorSet.get());
  PlagiasmResult result = checkLibary.getSimilaity(firstProgram,secondProgram);
  return result;
}
