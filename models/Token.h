//
// Created by anton on 19.04.19.
//

#include "TokenType.h"
#include <string>
#ifndef COOLSTEALNIGHT_TOKEN_H
#define COOLSTEALNIGHT_TOKEN_H

class Token {
public:
  Token() = default;

  Token(TokenType type, const std::string &data);

  TokenType getType() const;

  void setType(TokenType type);

  const std::string &getData() const;

  void setData(const std::string &data);

private:
  TokenType type;
  std::string data;
};

#endif // COOLSTEALNIGHT_TOKEN_H
