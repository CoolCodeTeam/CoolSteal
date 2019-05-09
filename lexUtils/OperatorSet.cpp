//
// Created by alexis on 03.05.19.
//
#include "OperatorSet.h"
const string cppOperators[] = {
    "+",    "-",   "/",      "%",      "*",     "=",        "==",     "<=",
    ">=",   "!=",  "++",     "--",     ">",     "<",        "!",      "&&",
    "||",   "~",   "|",      "&",      "^",     "<<",       ">>",     "+=",
    "-=",   "*=",  "/=",     "%=",     "&=",    "|=",       "^=",     "<<=",
    ">>=",  ".",   "->",     "[",      "]",     "(",        ")",      "{",
    "}",    "new", "delete", "::",     ",",     "alignof",  "sizeof", "?",
    ":",    ";",   "return", "switch", "break", "continue", "if",     "else",
    "goto", "for", "while",  "do"

};

const string cppOpComp[]{"+", "-", "/", "%", "*", "=", ">",
                         "<", "!", "|", "&", "^", ":"};

OperatorSet::OperatorSet(const string &language) {
  if (language == "CPP") {
    for (int i = 0; i < end(cppOperators) - begin(cppOperators); i++)
      keyWords.insert(cppOperators[i]);
    for (int i = 0; i < end(cppOpComp) - begin(cppOpComp); i++)
      keyWordsComp.insert(cppOpComp[i]);
  }
}

bool OperatorSet::isToken(const string &string) {
  for (int i = 0; i < keyWords.size(); i++) {
    if (keyWords.count(string) > 0)
      return true;
  };
}

bool OperatorSet::canBeCompound(const string &string) {
  for (int i = 0; i < keyWordsComp.size(); i++) {
    if (keyWordsComp.count(string) > 0)
      return true;
  };
}