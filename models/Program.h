//
// Created by anton on 19.04.19.
//
#include <time.h>
#include <iostream>
#include <set>
#include <vector>
#include "../rapidjson/document.h"
#include "../rapidjson/writer.h"
#include "../rapidjson/reader.h"
#include "../rapidjson/stringbuffer.h"
#include "../rapidjson/stringbuffer.h"

#ifndef COOLSTEALNIGHT_PROGRAMM_H
#define COOLSTEALNIGHT_PROGRAMM_H


class Program{
public:
    Program(const std::string &sourseCode, long ownerId, const std::string &lang);

    Program(const std::string &sourseCode);

  friend std::ostream &operator<<(std::ostream &os, const Program &program);

  Program();

    long getId() const;

    const std::string &getName() const;

    const std::string &getSourseCode() const;

    const std::string &getNormalizeCode() const;

    const std::set<std::string> &getShingleSet() const;

    const std::string &getTokenSet() const;

    long getOwnerId() const;

    const std::string &getLang() const;

    void setId(long id);

    void setName(const std::string &name);

    void setSourseCode(const std::string &sourseCode);

    void setNormalizeCode(const std::string &normalizeCode);

    void setShingleSet(const std::set<std::string> &shingleSet);

    void setTokenSet(const std::string &tokenSet);

    void setOwnerId(long ownerId);

    void setLang(const std::string &lang);

    static Program fromJSON(const rapidjson::Value& doc);

  rapidjson::Document toJSON();


private:
    long id;
    std::string name;
    std::string sourseCode;
    std::string normalizeCode;
    std::set<std::string> shingleSet;
    std::string tokenSet;
    long ownerId;
    //Date date
    std::string lang;

};



#endif //COOLSTEALNIGHT_PROGRAMM_H
