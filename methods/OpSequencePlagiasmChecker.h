//
// Created by alexis on 17.05.19.
//
#include "../models/Program.h"
#include "Checker.h"
#ifndef COOLSTEAL_OPSEQUENCEPLAGIASMCHECKER_H
#define COOLSTEAL_OPSEQUENCEPLAGIASMCHECKER_H
using namespace std;

class OpSequencePlagiasmChecker : public Checker {
public:
  OpSequencePlagiasmChecker() = default;
  int check(Program &originalProgram, const Program &comparedProgram) override;
  int check(Program &originalProgram, Program &comparedProgram) override;

private:
  int sequenceComparison(vector<Token> &firstOp, vector<Token> &secondOp);
};

#endif // COOLSTEAL_OPSEQUENCEPLAGIASMCHECKER_H
