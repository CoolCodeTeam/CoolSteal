//
// Created by anton on 19.04.19.
//

#include "PlagiasmResult.h"

PlagiasmResult::PlagiasmResult(int uId,int shingleResult, int levenstainResult, int operatorPlagiasmResult,
                               int mostSimilarProgrammId) : id(uId),shingleResult(shingleResult),
                                                            levenstainResult(levenstainResult),
                                                            operatorPlagiasmResult(operatorPlagiasmResult), mostSimilarProgrammId(mostSimilarProgrammId){}

int PlagiasmResult::getShingleResult() const {
  return shingleResult;
}

int PlagiasmResult::getLevenstainResult() const {
  return levenstainResult;
}

int PlagiasmResult::getOperatorPlagiasmResult() const {
  return operatorPlagiasmResult;
}

rapidjson::Document PlagiasmResult::toJSON() {
  rapidjson::Value json_val;
  rapidjson::Document doc;
  auto &allocator = doc.GetAllocator();

  doc.SetObject();

  json_val.SetUint64(shingleResult);
  doc.AddMember("shingleResult", json_val, allocator);

  json_val.SetUint64(levenstainResult);
  doc.AddMember("levenstainResult", json_val, allocator);

  json_val.SetUint64(operatorPlagiasmResult);
  doc.AddMember("operatorPlagiasm", json_val, allocator);

  return doc;
}
PlagiasmResult::PlagiasmResult() {
;
}
PlagiasmResult PlagiasmResult::fromJson(const rapidjson::Value& doc) {
  int uId = doc["id"].GetInt();
  int shingleResult = doc["result"]["m1"].GetInt();
  int levenstainResult = doc["result"]["m2"].GetInt();
  int operatorResult = doc["result"]["m1"].GetInt();
  int mostSimilarProgramUid = doc["mostSimilarProgram"].GetInt();


  return PlagiasmResult(uId,shingleResult,levenstainResult,operatorResult,mostSimilarProgramUid);
}
int PlagiasmResult::getId() const {
  return id;
}
void PlagiasmResult::setId(int id) {
  PlagiasmResult::id = id;
}
void PlagiasmResult::setShingleResult(int shingleResult) {
  PlagiasmResult::shingleResult = shingleResult;
}
void PlagiasmResult::setLevenstainResult(int levenstainResult) {
  PlagiasmResult::levenstainResult = levenstainResult;
}
void PlagiasmResult::setOperatorPlagiasmResult(int operatorPlagiasmResult) {
  PlagiasmResult::operatorPlagiasmResult = operatorPlagiasmResult;
}
int PlagiasmResult::getMostSimilarProgrammId() const {
  return mostSimilarProgrammId;
}
void PlagiasmResult::setMostSimilarProgrammId(int mostSimilarProgrammId) {
  PlagiasmResult::mostSimilarProgrammId = mostSimilarProgrammId;
}
std::ostream &operator<<(std::ostream &os, const PlagiasmResult &result) {
  os << "id: " << result.id << " shingleResult: " << result.shingleResult << " levenstainResult: "
     << result.levenstainResult << " operatorPlagiasmResult: " << result.operatorPlagiasmResult
     << " mostSimilarProgrammId: " << result.mostSimilarProgrammId;
  return os;
}

