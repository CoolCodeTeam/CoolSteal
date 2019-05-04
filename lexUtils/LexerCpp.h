//
// Created by alexis on 02.05.19.
//
#include "../models/Program.h"
#include "../models/Token.h"
#include "../models/TokenType.h"
#include "CKeyWords.h"
#include "LexerInterface.h"
#include "OperatorSet.h"
#include "VariableSet.h"
#ifndef COOLSTEAL_LEXER_H
#define COOLSTEAL_LEXER_H

class LexerCpp : public LexerInterface {
private:
  vector<Token> tokens;
  set<string> cycleSet;
  CKeyWords cKeyWords;
  OperatorSet opSet;
  VariableSet varSet;
  void makeCycleSet();
  bool isCycle(const string &string);
  bool isCondition(const string &string);
  bool isValue(const char &ch);
  bool isNumber(const char &ch);
  bool isLetter(const char &ch);

public:
  LexerCpp() = default;
  vector<Token> getTokenSet(const Program &sourseProgram) override;
};

#endif // COOLSTEAL_LEXER_H
