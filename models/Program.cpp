//
// Created by anton on 19.04.19.
//
#include <iostream>
#include "Program.h"

Program::Program(const std::string &sourseCode) : sourseCode(sourseCode) {}

Program::Program() {}

long Program::getId() const {
    return id;
}

const std::string &Program::getName() const {
    return name;
}

const std::string &Program::getSourseCode() const {
    return sourseCode;
}

const std::string &Program::getNormalizeCode() const {
    return normalizeCode;
}

const std::set<std::string> &Program::getShingleSet() const {
    return shingleSet;
}

const std::vector<std::string> &Program::getTokenSet() const {
    return tokenSet;
}

long Program::getOwnerId() const {
    return ownerId;
}

const std::string &Program::getLang() const {
    return lang;
}

void Program::setId(long id) {
    Program::id = id;
}

void Program::setName(const std::string &name) {
    Program::name = name;
}

void Program::setSourseCode(const std::string &sourseCode) {
    Program::sourseCode = sourseCode;
}

void Program::setNormalizeCode(const std::string &normalizeCode) {
    Program::normalizeCode = normalizeCode;
}

void Program::setShingleSet(const std::set<std::string> &shingleSet) {
    Program::shingleSet = shingleSet;
}

void Program::setTokenSet(const std::vector<std::string> &tokenSet) {
    Program::tokenSet = tokenSet;
}

void Program::setOwnerId(long ownerId) {
    Program::ownerId = ownerId;
}

void Program::setLang(const std::string &lang) {
    Program::lang = lang;
}