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
  return -1;
}
PlagiasmResult Router::comparePrograms(Program &firstProgram, Program &secondProgram) {
  return checker.comparePrograms(firstProgram,secondProgram);
}