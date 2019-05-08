//
// Created by alexis on 02.05.19.
//

#include "LexerCpp.h"
#include <cassert>

const string cycles[] = {"for", "while", "do"};

void LexerCpp::makeCycleSet() {
  for (int i = 0; i < end(cycles) - begin(cycles); i++)
    cycleSet.insert(cycles[i]);
}

bool LexerCpp::isCycle(const string &string) {
  makeCycleSet();
  for (int i = 0; i < cycleSet.size(); i++) {
    if (cycleSet.count(string) > 0)
      return true;
  };
}

bool LexerCpp::isCondition(const string &string) {
  if (string == "if" || string == "case")
    ;
}

bool LexerCpp::isValue(const char &ch) { return (ch == 39 || ch == 34); }

bool LexerCpp::isNumber(const char &ch) { return (ch >= 48 && ch <= 57); }

bool LexerCpp::isLetter(const char &ch) {
  return ((ch >= 97 && ch <= 122) || (ch >= 65 && ch <= 90) || ch == 95);
}

vector<Token> LexerCpp::getTokenSet(const Program &sourseProgram) {
  tokens.clear();
  const string normCode = sourseProgram.getNormalizeCode();
  string lastWord;
  string notFullWord;
  string lastCycle;
  char lastToken = ' ';
  cKeyWords = CKeyWords();
  opSet = OperatorSet(sourseProgram.getLang());
  varSet = VariableSet(sourseProgram.getLang());

  for (int i = 0; i < normCode.size();) {
    //cout << lastWord << endl;
    string word;
    Token token;
    if (normCode[i] == ' ') {
      lastToken = normCode[i];
      i++;
      continue;
    }
    if (normCode[i] == '#') { // preprocessor directives
      word.push_back(normCode[i]);
      i++;
      while (isLetter(normCode[i])) {
        word.push_back(normCode[i]);
        i++;
      }
      if (cKeyWords.isToken(word)) {
        token = Token(KEYWORD, word);
      } else
        assert(cKeyWords.isToken(word));
      tokens.push_back(token);
      lastWord = word;
      lastToken = normCode[i - 1];
      continue;
    }
    if (normCode[i] == '<') {
      if (cKeyWords.isDirective(lastWord)) {
        word.push_back(normCode[i]);
        i++;
        while (normCode[i] != '>') {
          word.push_back(normCode[i]);
          i++;
        }
        word.push_back(normCode[i]);
        lastToken = normCode[i];
        i++;
        token = Token(VALUE_TYPE, word);
        tokens.push_back(token);
        lastWord = word;
        continue;
      } else {
        notFullWord.push_back('<');
        string a;
        a.push_back(normCode[i + 1]);
        if (opSet.isToken(a)) {
          i++;
          lastToken = '<';
        } else {
          if (opSet.isToken(notFullWord)) {
            token = Token(OPERATOR, notFullWord);
          }
          tokens.push_back(token);
          i++;
          lastToken = '<';
          lastWord = notFullWord;
          notFullWord = "";
        }
        continue;
      }
    }
    if (isLetter(normCode[i])) {
      word.push_back(normCode[i]);
      i++;
      while (isLetter(normCode[i]) || isNumber(normCode[i])) {
        word.push_back(normCode[i]);
        i++;
      }
      lastToken = normCode[i - 1];
      if (isCycle(word)) {
        if (lastCycle != "do") {
          token = Token(CYCLE, word);
          tokens.push_back(token);
        }
        lastWord = word;
        lastCycle = word;
      } else if (isCondition(word)) {
        token = Token(CONDITION, word);
        tokens.push_back(token);
        lastWord = word;
      } else if (opSet.isToken(word)) {
        token = Token(OPERATOR, word);
        tokens.push_back(token);
        lastWord = word;
      } else if (varSet.isToken(word)) {
        if (varSet.isToken(lastWord)) {
          lastWord += " ";
          lastWord += word;
          tokens[tokens.size()].setData(lastWord);
        } else {
          token = Token(VARIABLE_TYPE, word);
          tokens.push_back(token);
          lastWord = word;
        }
      } else if (cKeyWords.isToken(word)) {
        token = Token(KEYWORD, word);
        tokens.push_back(token);
        lastWord = word;
      } else {
        token = Token(IDENTIFICATOR, word);
        tokens.push_back(token);
        lastWord = word;
      }
      continue;
    }
    if (isNumber(normCode[i])) {
      word.push_back(normCode[i]);
      i++;
      while (isNumber(normCode[i]) || normCode[i] == '.') {
        word.push_back(normCode[i]);
        i++;
      }
      lastToken = normCode[i - 1];
      token = Token(VALUE_TYPE, word);
      tokens.push_back(token);
      lastWord = word;
      continue;
    }
    if (isValue(normCode[i])) {
      word.push_back(normCode[i]);
      i++;
      while (!isValue(normCode[i])) {
        word.push_back(normCode[i]);
        i++;
      }
      lastToken = normCode[i];
      word.push_back(normCode[i]);
      i++;
      token = Token(VALUE_TYPE, word);
      tokens.push_back(token);
      lastWord = word;
      continue;
    } else {
      word.push_back(normCode[i]);
      if (!opSet.canBeCompound(word)) {
        token = Token(OPERATOR, word);
        tokens.push_back(token);
        lastWord = word;
        lastToken = normCode[i];
        i++;
      } else {
        notFullWord.push_back(normCode[i]);
        string a;
        a.push_back(normCode[i + 1]);
        if (opSet.canBeCompound(a)) {
          i++;
          lastToken = normCode[i - 1];
        } else {
          if (opSet.isToken(notFullWord)) {
            token = Token(OPERATOR, notFullWord);
          }
          tokens.push_back(token);
          i++;
          lastToken = normCode[i];
          lastWord = notFullWord;
          notFullWord = "";
        }
      }
      continue;
    }
  }
  return tokens;
}

std::string LexerCpp::getTokens(const Program &sourseProgram) {
  vector<Token> tokens = getTokenSet(sourseProgram);
  std::string result;
  for (int i = 0;i<tokens.size();i++){
    result+= std::to_string(tokens[i].getType());
  }
  return result;
}

