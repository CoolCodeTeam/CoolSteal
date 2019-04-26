//
// Created by anton on 19.04.19.
//

#include "PlagiasmResult.h"

PlagiasmResult::PlagiasmResult(int shingleResult, int levenstainResult, int operatorPlagiasmResult,
                               int mostSimilarProgrammId) : shingleResult(shingleResult),
                                                            levenstainResult(levenstainResult),
                                                            operatorPlagiasmResult(operatorPlagiasmResult) {}

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
  doc.AddMember("shingleResult", json_val, allocator);

  json_val.SetUint64(operatorPlagiasmResult);
  doc.AddMember("shingleResult", json_val, allocator);

  return doc;
}

