//
// Created by anton on 04.05.19.
//

#ifndef COOLSTEAL_NORMALIZATOR_H
#define COOLSTEAL_NORMALIZATOR_H

#include "NormalizatorInterface.h"
#include "NormalizeAlgorhitm.h"
class Normalizator: public NormalizatorInterface {
 public:
  std::string normalize(const Program &program) override;
  ~Normalizator();
 private:
   NormalizeAlgorithm* configureNormalizer(std::string lang);
   NormalizeAlgorithm* algorithm;
};

#endif //COOLSTEAL_NORMALIZATOR_H
