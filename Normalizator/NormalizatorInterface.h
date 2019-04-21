//
// Created by anton on 21.04.19.
//

#ifndef COOLSTEALNIGHT_NORMALIZATORINTERFACE_H
#define COOLSTEALNIGHT_NORMALIZATORINTERFACE_H

#include <string>
#include "../models/Program.h"
class NormalizatorInterface{
public:
private:
    virtual std::string normalize(const Program &program)=0;
};
#endif //COOLSTEALNIGHT_NORMALIZATORINTERFACE_H
