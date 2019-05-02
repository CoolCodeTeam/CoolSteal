//
// Created by anton on 19.04.19.
//
#include <time.h>
#include <iostream>
#include <set>
#include <vector>

#ifndef COOLSTEALNIGHT_PROGRAMM_H
#define COOLSTEALNIGHT_PROGRAMM_H

class Program {
public:
    Program(const std::string& sourseCode);

    Program();

    long
    getId() const;

    const std::string&
    getName() const;

    const std::string&
    getSourseCode() const;

    const std::string&
    getNormalizeCode() const;

    const std::set<std::string>&
    getShingleSet() const;

    const std::string&
    getTokenSet() const;

    long
    getOwnerId() const;

    const std::string&
    getLang() const;

    void
    setId(long id);

    void
    setName(const std::string& name);

    void
    setSourseCode(const std::string& sourseCode);

    void
    setNormalizeCode(const std::string& normalizeCode);

    void
    setShingleSet(const std::set<std::string>& shingleSet);

    void
    setTokenSet(const std::string& tokenSet);

    void
    setOwnerId(long ownerId);

    void
    setLang(const std::string& lang);

private:
    long id;
    long ownerId;
    std::string name;
    std::string lang;
    std::string sourseCode;
    std::string normalizeCode;
    std::string tokenSet;
    //Date date

    std::set<std::string> shingleSet;

};

#endif //COOLSTEALNIGHT_PROGRAMM_H
