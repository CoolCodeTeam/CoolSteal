//
// Created by alexis on 17.05.19.
//

#include "../models/Program.h"
#include "Checker.h"
#include "../models/Token.h"
#include <map>

#ifndef COOLSTEAL_OPERATORPLAGIASMCHECKER_H
#define COOLSTEAL_OPERATORPLAGIASMCHECKER_H
using namespace std;

class OperatorPlagiasmChecker : public Checker {
public:
  OperatorPlagiasmChecker() = default;
  int check(Program &originalProgram, const Program &comparedProgram) override;
  int check(Program &originalProgram, Program &comparedProgram) override;

private:
  int quantityComparison(vector<Token> &firstOp, vector<Token> &secondOp);
  map<string, int> getMap(vector<Token> &operators);
  void print(map<string, int> &m);
};

#endif // COOLSTEAL_OPERATORPLAGIASMCHECKER_H
