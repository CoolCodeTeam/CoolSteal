//
// Created by alexey on 26.04.19.
//

#include "ShingleChecker.h"
#include <set>

ShingleChecker::ShingleChecker() = default;

int ShingleChecker::check(Program &originalProgram, const Program &comparedProgram) {
    if (originalProgram.getShingleSet().empty()) {
        makeShingleSet(originalProgram);
    }

    int coincidence = 0;

    for (auto originalIter = originalProgram.getShingleSet().begin();
         originalIter != originalProgram.getShingleSet().end();
         originalIter++) {
        if (comparedProgram.getShingleSet().find(*originalIter) != comparedProgram.getShingleSet().end())
            coincidence++;
    }
    return coincidence * 100 / originalProgram.getShingleSet().size();      // TODO: прогрессивная формула
}

std::string ShingleChecker::hash(const std::string &key) {                  // TODO: нормальный хеш
    int hash = 0;
    for (int i = 0; i < key.size(); i++)
        hash = (hash * 127 + key[i]);
    return std::to_string(hash);
}

void ShingleChecker::makeShingleSet(Program &originalProgram) {
    std::set<std::string> shingleSet;

    for (auto iter = originalProgram.getTokenSet().begin();
         iter <= originalProgram.getTokenSet().end() - K;
         iter++) {

        std::string shingle;
        for (auto innerIter = iter; innerIter < iter + K; innerIter++) {
            shingle += *innerIter;
        }

        std::string shingleHash = hash(shingle);
        shingleSet.insert(shingleHash);
    }
    originalProgram.setShingleSet(shingleSet);
}