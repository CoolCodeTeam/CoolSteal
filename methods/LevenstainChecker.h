//
// Created by anton on 02.05.19.
//

#ifndef COOLSTEAL_LEVENSTAINCHECKER_H
#define COOLSTEAL_LEVENSTAINCHECKER_H

#include "Checker.h"
class LevenstainChecker: public Checker {
 public:
  int check(Program &originalProgram, const Program &comparedProgram) override;
  int check(Program& originalProgram, Program& comparedProgram) override;
 private:
  int getEditDist(std::string str1, std::string str2,int m,int n);
  int min(int x,int y,int z);
};

#endif //COOLSTEAL_LEVENSTAINCHECKER_H
