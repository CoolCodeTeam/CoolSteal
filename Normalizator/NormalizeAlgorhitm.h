//
// Created by anton on 04.05.19.
//

#ifndef COOLSTEAL_NORMALIZEALGORHITM_H
#define COOLSTEAL_NORMALIZEALGORHITM_H
#include <string>
#include <algorithm>
#include <iostream>
#include "../models/Program.h"
class NormalizeAlgorithm{
 public:
  virtual std::string run(const Program &program)=0;
};
#endif //COOLSTEAL_NORMALIZEALGORHITM_H
