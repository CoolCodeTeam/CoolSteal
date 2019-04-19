//
// Created by anton on 19.04.19.
//

#include "../models/PlagiasmResult.h"
#include "../models/Program.h"

class CheckLibaryInterface{
public:
    virtual int getSimilaity(Program originalProgram,Program comparedProgram)=0;
    virtual int getShingleResult(Program originalProgram,Program comparedProgram)=0;
    virtual int getLevemstainResult(Program originalProgram,Program comparedProgram)=0;
    virtual int getOperatorPlagiasmResultResult(Program originalProgram,Program comparedProgram)=0;
};

