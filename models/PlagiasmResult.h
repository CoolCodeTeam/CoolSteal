//
// Created by anton on 19.04.19.
//

#ifndef COOLSTEALNIGHT_PLAGIASMRESULT_H
#define COOLSTEALNIGHT_PLAGIASMRESULT_H

#include <ostream>
#include "../rapidjson/document.h"
#include "../rapidjson/writer.h"
#include "../rapidjson/reader.h"
#include "../rapidjson/stringbuffer.h"
#include "../rapidjson/stringbuffer.h"

class PlagiasmResult {
 public:
  PlagiasmResult();
  PlagiasmResult(int Uid,int shingleResult, int levenstainResult, int operatorPlagiasmResult, int mostSimilarProgrammId);
  PlagiasmResult(int shingleResult, int levenstainResult, int operatorPlagiasmResult);

  int getShingleResult() const;

  int getLevenstainResult() const;

  int getOperatorPlagiasmResult() const;
  int getId() const;
  void setId(int id);
  void setShingleResult(int shingleResult);
  void setLevenstainResult(int levenstainResult);
  void setOperatorPlagiasmResult(int operatorPlagiasmResult);
  int getMostSimilarProgrammId() const;
  void setMostSimilarProgrammId(int mostSimilarProgrammId);
  rapidjson::Document toJSON();
  static PlagiasmResult fromJson(const rapidjson::Value& doc);
  float getGeneralSimilarity();

  friend std::ostream &operator<<(std::ostream &os, const PlagiasmResult &result);

 private:
  int id;
  int shingleResult;
  int levenstainResult;
  int operatorPlagiasmResult;
  int mostSimilarProgrammId;

};

#endif //COOLSTEALNIGHT_PLAGIASMRESULT_H
