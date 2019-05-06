//
// Created by alexis on 02.05.19.
//
#include "TokenSet.h"
#ifndef COOLSTEAL_OPERATORSET_H
#define COOLSTEAL_OPERATORSET_H

class OperatorSet : public TokenSet {
private:
  set<string> keyWords;
  set<string> keyWordsComp;
  string language;

public:
  OperatorSet() = default;
  OperatorSet(const string &language);
  bool isToken(const string &string) override;
  bool canBeCompound(const string &string);
};

#endif // COOLSTEAL_OPERATORSET_H