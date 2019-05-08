//
// Created by alexis on 03.05.19.
//

#include "VariableSet.h"
#include <iostream>

const string cppVars[] = {"bool",     "signed char", "unsigned char", "char",
                          "wchar_t",  "char16_t",    "char32_t",      "signed",
                          "unsigned", "short",       "int",           "long",
                          "float",    "double"};

VariableSet::VariableSet(const string &language) {
  if (language == "CPP") {
    for (int i = 0; i < end(cppVars) - begin(cppVars); i++)
      keyWords.insert(cppVars[i]);
  }
}

bool VariableSet::isToken(const string &string) {
  for (int i = 0; i < keyWords.size(); i++) {
    if (keyWords.count(string) > 0)
      return true;
  };
}