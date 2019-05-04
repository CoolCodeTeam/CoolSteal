//
// Created by alexis on 02.05.19.
//
#include "TokenSet.h"

#ifndef COOLSTEAL_CKEYWORDS_H
#define COOLSTEAL_CKEYWORDS_H

class CKeyWords : public TokenSet {
private:
  set<string> keyWords;
  set<string> keyWordsDir;

public:
  CKeyWords();
  bool isToken(const string &string) override;
  bool isDirective(const string &string);
};

#endif // COOLSTEAL_CKEYWORDS_H