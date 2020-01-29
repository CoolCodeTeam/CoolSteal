//
// Created by anton on 26.04.19.
//

#include "Router.h"
Router::Router() {
;
}
PlagiasmResult Router::checkProgram(Program &program) {
  return checker.checkProgramWithDB(program);
}
int Router::getNewId() {
  return dbManager.getNewId();
}
PlagiasmResult Router::comparePrograms(Program &firstProgram, Program &secondProgram) {
  return checker.comparePrograms(firstProgram,secondProgram);
}
Program Router::getProgramById(int id) {
  return dbManager.getProgram(id);
}
