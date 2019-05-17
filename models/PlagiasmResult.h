//
// Created by anton on 19.04.19.
//

#ifndef COOLSTEALNIGHT_PLAGIASMRESULT_H
#define COOLSTEALNIGHT_PLAGIASMRESULT_H

#include "rapidjson/document.h"
#include "rapidjson/reader.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"
#include <ostream>

class PlagiasmResult {
public:
  PlagiasmResult();
  PlagiasmResult(int Uid, int shingleResult, int levenstainResult,
                 int operatorPlagiasmResult, int opSequencePlagiasmResult,
                 int mostSimilarProgrammId);
  PlagiasmResult(int shingleResult, int levenstainResult,
                 int operatorPlagiasmResult, int opSequencePlagiasmResult);

  int getShingleResult() const;

  int getLevenstainResult() const;

  int getOperatorPlagiasmResult() const;
  int getOpSequencePlagiasmResult() const;
  int getId() const;
  void setId(int id);
  void setShingleResult(int shingleResult);
  void setLevenstainResult(int levenstainResult);
  void setOperatorPlagiasmResult(int operatorPlagiasmResult);
  void setOpSequencePlagiasmResult(int opSequencePlagiasmResult);
  int getMostSimilarProgrammId() const;
  void setMostSimilarProgrammId(int mostSimilarProgrammId);
  rapidjson::Document toJSON();
  static PlagiasmResult fromJson(const rapidjson::Value &doc);
  float getGeneralSimilarity();

  friend std::ostream &operator<<(std::ostream &os,
                                  const PlagiasmResult &result);

private:
  int id;
  int shingleResult;
  int levenstainResult;
  int operatorPlagiasmResult;
  int opSequencePlagiasmResult;
  int mostSimilarProgrammId;
};

#endif // COOLSTEALNIGHT_PLAGIASMRESULT_H
