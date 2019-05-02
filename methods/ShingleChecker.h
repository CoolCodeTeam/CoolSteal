
#ifndef COOLSTEAL_SHINGLECHECKER_H
#define COOLSTEAL_SHINGLECHECKER_H

#include "../models/Program.h"
#include "Checker.h"

class ShingleChecker : public Checker {
 public:
  ShingleChecker();
  int check(Program& originalProgram, const Program& comparedProgram) override;
  int check(Program& originalProgram, Program& comparedProgram) override;

 private:
  std::string hash_MD5(const std::string& key);
  std::string hash_SHA1(const std::string& key);
  void makeShingleSet(Program& originalProgram);
  const int K = 20;
};

#endif //COOLSTEAL_SHINGLECHECKER_H