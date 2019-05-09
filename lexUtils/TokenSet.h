//
// Created by alexis on 02.05.19.
//
#include <set>
#include <string>
#ifndef COOLSTEAL_TOKENSET_H
#define COOLSTEAL_TOKENSET_H
using namespace std;
class TokenSet {
private:
  set<string> keyWords;

public:
  virtual bool isToken(const string &string) = 0;
};
#endif // COOLSTEAL_TOKENSET_H