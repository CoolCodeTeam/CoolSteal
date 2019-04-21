//
// Created by anton on 19.04.19.
//

#ifndef COOLSTEALNIGHT_PLAGIASMRESULT_H
#define COOLSTEALNIGHT_PLAGIASMRESULT_H


class PlagiasmResult {
public:
    PlagiasmResult(int shingleResult, int levenstainResult, int operatorPlagiasmResult, int mostSimilarProgrammId);

    int getShingleResult() const;

    int getLevenstainResult() const;

    int getOperatorPlagiasmResult() const;


private:
    int shingleResult;
    int levenstainResult;
    int operatorPlagiasmResult;


};


#endif //COOLSTEALNIGHT_PLAGIASMRESULT_H
