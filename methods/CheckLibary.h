//
// Created by anton on 19.04.19.
//

#include "../models/PlagiasmResult.h"
#include "../models/Program.h"

class CheckLibaryInterface {
 public:
  virtual PlagiasmResult getSimilaity(Program &originalProgram, const Program &comparedProgram)=0;
  virtual int getShingleResult(Program &originalProgram, const Program &comparedProgram)=0;
  virtual int getLevemstainResult(Program &originalProgram, const Program &comparedProgram)=0;
  virtual int getOperatorPlagiasmResultResult(Program &originalProgram, const Program &comparedProgram)=0;
};

