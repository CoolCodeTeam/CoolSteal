//
// Created by anton on 19.04.19.
//
#include <time.h>
#include <iostream>
#include <set>
#include <vector>

#ifndef COOLSTEALNIGHT_PROGRAMM_H
#define COOLSTEALNIGHT_PROGRAMM_H


class Programm{
public:
    Programm(const std::string &sourseCode);

    Programm();

    long getId() const;

    const std::string &getName() const;

    const std::string &getSourseCode() const;

    const std::string &getNormalizeCode() const;

    const std::set<std::string> &getShingleSet() const;

    const std::vector<std::string> &getTokenSet() const;

    long getOwnerId() const;

    const std::string &getLang() const;

    void setId(long id);

    void setName(const std::string &name);

    void setSourseCode(const std::string &sourseCode);

    void setNormalizeCode(const std::string &normalizeCode);

    void setShingleSet(const std::set<std::string> &shingleSet);

    void setTokenSet(const std::vector<std::string> &tokenSet);

    void setOwnerId(long ownerId);

    void setLang(const std::string &lang);

private:
    long id;
    std::string name;
    std::string sourseCode;
    std::string normalizeCode;
    std::set<std::string> shingleSet;
    std::vector<std::string> tokenSet;
    long ownerId;
    //Date date
    std::string lang;

};

Programm::Programm(const std::string &sourseCode) : sourseCode(sourseCode) {}

Programm::Programm() {}

long Programm::getId() const {
    return id;
}

const std::string &Programm::getName() const {
    return name;
}

const std::string &Programm::getSourseCode() const {
    return sourseCode;
}

const std::string &Programm::getNormalizeCode() const {
    return normalizeCode;
}

const std::set<std::string> &Programm::getShingleSet() const {
    return shingleSet;
}

const std::vector<std::string> &Programm::getTokenSet() const {
    return tokenSet;
}

long Programm::getOwnerId() const {
    return ownerId;
}

const std::string &Programm::getLang() const {
    return lang;
}

void Programm::setId(long id) {
    Programm::id = id;
}

void Programm::setName(const std::string &name) {
    Programm::name = name;
}

void Programm::setSourseCode(const std::string &sourseCode) {
    Programm::sourseCode = sourseCode;
}

void Programm::setNormalizeCode(const std::string &normalizeCode) {
    Programm::normalizeCode = normalizeCode;
}

void Programm::setShingleSet(const std::set<std::string> &shingleSet) {
    Programm::shingleSet = shingleSet;
}

void Programm::setTokenSet(const std::vector<std::string> &tokenSet) {
    Programm::tokenSet = tokenSet;
}

void Programm::setOwnerId(long ownerId) {
    Programm::ownerId = ownerId;
}

void Programm::setLang(const std::string &lang) {
    Programm::lang = lang;
}

#endif //COOLSTEALNIGHT_PROGRAMM_H
