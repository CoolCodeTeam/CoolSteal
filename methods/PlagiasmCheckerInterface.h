//
// Created by alexey on 26.04.19.
//

#ifndef COOLSTEALNIGHT_PLAGIASMCHECKERINTERFACE_H
#define COOLSTEALNIGHT_PLAGIASMCHECKERINTERFACE_H

#include "../models/Program.h"

class PlagiasmCheckerInterface {
 public:
  virtual int check(Program &originalProgram, const Program &comparedProgram) = 0;
};


#endif //COOLSTEALNIGHT_PLAGIASMCHECKERINTERFACE_H
