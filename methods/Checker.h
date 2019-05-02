
#pragma once
#include "../models/Program.h"



class Checker {
 public:
  virtual int check(Program &originalProgram, const Program &comparedProgram) = 0;
  virtual int check(Program &originalProgram, Program &comparedProgram) = 0;
};