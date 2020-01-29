//
// Created by anton on 04.05.19.
//

#include "Normalizator.h"
#include "CppNormaizeAlgorithm.h"
std::string Normalizator::normalize(const Program &program) {
  algorithm = configureNormalizer(program.getLang());
  return algorithm->run(program);
}
NormalizeAlgorithm* Normalizator::configureNormalizer(std::string lang) {
  if (strcmp(lang.c_str(),"CPP") == 0){
    return new CppNormaizeAlgorithm();//TODO: Пробел в конце программы всё ломает
  }
  return new CppNormaizeAlgorithm();
}
Normalizator::~Normalizator() {
//  if (algorithm)
//    delete (algorithm);TODO:FIX
}
