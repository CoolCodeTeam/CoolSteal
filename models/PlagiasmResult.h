//
// Created by anton on 19.04.19.
//

#ifndef COOLSTEALNIGHT_PLAGIASMRESULT_H
#define COOLSTEALNIGHT_PLAGIASMRESULT_H

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/reader.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/stringbuffer.h"

class PlagiasmResult {
 public:
  PlagiasmResult(int shingleResult, int levenstainResult, int operatorPlagiasmResult, int mostSimilarProgrammId);

  int getShingleResult() const;

  int getLevenstainResult() const;

  int getOperatorPlagiasmResult() const;

  rapidjson::Document toJSON();

 private:
  int shingleResult;
  int levenstainResult;
  int operatorPlagiasmResult;

};

#endif //COOLSTEALNIGHT_PLAGIASMRESULT_H
