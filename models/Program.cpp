//
// Created by anton on 19.04.19.
//
#include "Program.h"
#include <iostream>

Program::Program(const std::string &sourseCode) : sourseCode(sourseCode) {}

Program::Program() {}

long Program::getId() const { return id; }

const std::string &Program::getName() const { return name; }

const std::string &Program::getSourseCode() const { return sourseCode; }

const std::string &Program::getNormalizeCode() const { return normalizeCode; }

const std::set<std::string> &Program::getShingleSet() const {
  return shingleSet;
}

const std::string &Program::getTokenSet() const { return tokenSet; }

const std::vector<Token> &Program::getOperatorSet() const {
  return operatorSet;
}

long Program::getOwnerId() const { return ownerId; }

const std::string &Program::getLang() const { return lang; }

void Program::setId(long id) { Program::id = id; }

void Program::setName(const std::string &name) { Program::name = name; }

void Program::setSourseCode(const std::string &sourseCode) {
  Program::sourseCode = sourseCode;
}

void Program::setNormalizeCode(const std::string &normalizeCode) {
  Program::normalizeCode = normalizeCode;
}

void Program::setShingleSet(const std::set<std::string> &shingleSet) {
  Program::shingleSet = shingleSet;
}

void Program::setTokenSet(const std::string &tokenSet) {
  Program::tokenSet = tokenSet;
}

void Program::setOperatorSet(const std::vector<Token> &operatorSet) {
  Program::operatorSet = operatorSet;
}

void Program::setOwnerId(long ownerId) { Program::ownerId = ownerId; }

void Program::setLang(const std::string &lang) { Program::lang = lang; }

Program Program::fromJSON(const rapidjson::Value &doc) {

  std::string sourseCode = doc["sourseCode"].GetString();
  int ownerId = doc["id"].GetInt();
  std::string lang = doc["lang"].GetString();

  return Program(sourseCode, ownerId, lang);
}

Program::Program(const std::string &sourseCode, long ownerId,
                 const std::string &lang)
    : sourseCode(sourseCode), ownerId(ownerId), lang(lang) {}

rapidjson::Document Program::toJSON() {
  rapidjson::Value json_val;
  rapidjson::Document doc;
  auto &allocator = doc.GetAllocator();

  doc.SetObject();

  json_val.SetUint64(ownerId);
  doc.AddMember("id", json_val, allocator);

  json_val.SetString(sourseCode.c_str(), allocator);
  doc.AddMember("sourseCode", json_val, allocator);

  json_val.SetString(lang.c_str(), allocator);
  doc.AddMember("lang", json_val, allocator);

  return doc;
}
std::ostream &operator<<(std::ostream &os, const Program &program) {
  os << "sourseCode: " << program.sourseCode << " ownerId: " << program.ownerId
     << " lang: " << program.lang;
  return os;
}
