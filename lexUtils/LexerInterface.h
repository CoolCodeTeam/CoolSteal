//
// Created by anton on 19.04.19.
//

#include "../models/Program.h"
#include "../models/Token.h"
#include "../models/TokenType.h"
#ifndef COOLSTEALNIGHT_LEXERINTERFACE_H
#define COOLSTEALNIGHT_LEXERINTERFACE_H
using namespace std;
class LexerInterface {
public:
  virtual vector<Token> getTokenSet(const Program &sourseProgram) = 0;
  virtual std::string getTokens(const Program &sourseProgram)=0;
};
#endif // COOLSTEALNIGHT_LEXERINTERFACE_H
