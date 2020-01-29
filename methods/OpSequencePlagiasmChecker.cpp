//
// Created by alexis on 17.05.19.
//

#include "OpSequencePlagiasmChecker.h"

int OpSequencePlagiasmChecker::check(Program &originalProgram,
                                     Program &comparedProgram) {
  vector<Token> firstOp = originalProgram.getOperatorSet();
  vector<Token> secOp = comparedProgram.getOperatorSet();
  if (firstOp.size() > secOp.size())
    return sequenceComparison(firstOp, secOp);
  else
    return sequenceComparison(secOp, firstOp);
}

int OpSequencePlagiasmChecker::check(Program &originalProgram,
                                     const Program &comparedProgram) {
  vector<Token> firstOp = originalProgram.getOperatorSet();
  vector<Token> secOp = comparedProgram.getOperatorSet();
  if (firstOp.size() > secOp.size())
    return sequenceComparison(firstOp, secOp);
  else
    return sequenceComparison(secOp, firstOp);
}

int OpSequencePlagiasmChecker::sequenceComparison(vector<Token> &firstOp,
                                                  vector<Token> &secondOp) {
  if (firstOp.size()==0 || secondOp.size()==0){
    return 0;
  }
  int max = 0;
  int diff = firstOp.size() - secondOp.size();
  for (int i = 0; i <= diff; i++) {
    int count = 0;
    for (int j = 0; j < secondOp.size(); j++) {
      if (firstOp[i + j].getData() == secondOp[j].getData())
        count++;
    }
    if (count > max)
      max = count;
  }
  return max * 100 / firstOp.size();
}