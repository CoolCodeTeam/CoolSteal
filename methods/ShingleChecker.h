//
// Created by alexey on 26.04.19.
//

#ifndef COOLSTEAL_SHINGLECHECKER_H
#define COOLSTEAL_SHINGLECHECKER_H

#include "../models/Program.h"
#include "PlagiasmCheckerInterface.h"

class ShingleChecker : public PlagiasmCheckerInterface {
public:
    ShingleChecker();
    int check(Program& originalProgram, const Program& comparedProgram) override;

private:
    std::string hash(const std::string& key);
    void makeShingleSet(Program& originalProgram);
    const int K = 20;
};

#endif //COOLSTEAL_SHINGLECHECKER_H
