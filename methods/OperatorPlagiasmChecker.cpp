//
// Created by alexis on 17.05.19.
//

#include "OperatorPlagiasmChecker.h"

int OperatorPlagiasmChecker::check(Program &originalProgram,
                                   Program &comparedProgram) {
  vector<Token> firstOp = originalProgram.getOperatorSet();
  vector<Token> secOp = comparedProgram.getOperatorSet();
  return quantityComparison(firstOp, secOp);
}

int OperatorPlagiasmChecker::check(Program &originalProgram,
                                   const Program &comparedProgram) {
  vector<Token> firstOp = originalProgram.getOperatorSet();
  vector<Token> secOp = comparedProgram.getOperatorSet();
  return quantityComparison(firstOp, secOp);
}

int OperatorPlagiasmChecker::quantityComparison(vector<Token> &firstOp,
                                                vector<Token> &secondOp) {
  map<string, int> firstMap = getMap(firstOp);
  map<string, int> secondMap = getMap(secondOp);
  int count = 0;
  if (firstMap.size() < secondMap.size()) {
    for (map<string, int>::iterator it1 = firstMap.begin();
         it1 != firstMap.end(); it1++) {
      map<string, int>::iterator it2 = secondMap.find(it1->first);
      if (it2 != secondMap.end()) {
        if (it1->second == it2->second) {
          count++;
        }
      }
    }
    return (count * 100 / secondMap.size());
  } else {
    for (map<string, int>::iterator it1 = secondMap.begin();
         it1 != secondMap.end(); it1++) {
      map<string, int>::iterator it2 = firstMap.find(it1->first);
      if (it2 != firstMap.end()) {
        if (it1->second == it2->second) {
          count++;
        }
      }
    }
    return (count * 100 / firstMap.size());
  }
}

map<string, int> OperatorPlagiasmChecker::getMap(vector<Token> &operators) {
  map<string, int> opMap;
  for (int i = 0; i < operators.size(); i++) {
    string key = operators[i].getData();
    map<string, int>::iterator it = opMap.find(key);
    if (it == opMap.end())
      opMap.insert(pair<string, int>(key, 1));
    else
      it->second++;
  }
  return opMap;
}

void OperatorPlagiasmChecker::print(map<string, int> &m) {
  for (map<string, int>::iterator p = m.begin(); p != m.end(); p++)
    cout << (*p).first << ' ' << (*p).second << endl;
}