//
// Created by anton on 19.04.19.
//

#include <string>
#include "TokenType.h"
#ifndef COOLSTEALNIGHT_TOKEN_H
#define COOLSTEALNIGHT_TOKEN_H

class Token {
 public:
  Token(TokenType type, const std::string &data);

  TokenType getType() const;

  void setType(TokenType type);

  const std::string &getData() const;

  void setData(const std::string &data);

 private:
  TokenType type;
  std::string data;
};

#endif //COOLSTEALNIGHT_TOKEN_H
