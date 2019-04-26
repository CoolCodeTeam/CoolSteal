//
// Created by anton on 19.04.19.
//

#include "../models/Program.h"
#include "../models/TokenType.h"
#include "../models/Token.h"
#ifndef COOLSTEALNIGHT_LEXERINTERFACE_H
#define COOLSTEALNIGHT_LEXERINTERFACE_H
class LexerInterFace {
 public:
  virtual std::vector getTokenSet(const Program &sourseProgram)=0;
};
#endif //COOLSTEALNIGHT_LEXERINTERFACE_H
