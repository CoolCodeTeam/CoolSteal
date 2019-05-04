//
// Created by alexis on 03.05.19.
//
#include "TokenSet.h"
#ifndef COOLSTEAL_VARIABLESET_H
#define COOLSTEAL_VARIABLESET_H

class VariableSet : public TokenSet {
private:
  set<string> keyWords;
  string language;

public:
  VariableSet() = default;
  VariableSet(const string &language);
  bool isToken(const string &string) override;
};

#endif // COOLSTEAL_VARIABLESET_H
