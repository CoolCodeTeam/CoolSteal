//
// Created by anton on 19.04.19.
//

#include "PlagiasmResult.h"

PlagiasmResult::PlagiasmResult(int shingleResult, int levenstainResult, int operatorPlagiasmResult,
                               int mostSimilarProgrammId) : shingleResult(shingleResult),
                                                            levenstainResult(levenstainResult),
                                                            operatorPlagiasmResult(operatorPlagiasmResult)
                                                            {}

int PlagiasmResult::getShingleResult() const {
    return shingleResult;
}

int PlagiasmResult::getLevenstainResult() const {
    return levenstainResult;
}

int PlagiasmResult::getOperatorPlagiasmResult() const {
    return operatorPlagiasmResult;
}

