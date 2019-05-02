#include "ShingleChecker.h"

#include "Poco/MD5Engine.h"
#include "Poco/DigestStream.h"
#include "Poco/HMACEngine.h"
#include "Poco/SHA1Engine.h"

#include <set>

#define hash hash_SHA1

ShingleChecker::ShingleChecker() = default;

int ShingleChecker::check(Program &originalProgram, const Program &comparedProgram) {
  if (originalProgram.getShingleSet().empty()) {
    makeShingleSet(originalProgram);
  }

  int coincidence = 0;

  for (auto originalIter = originalProgram.getShingleSet().begin();
       originalIter != originalProgram.getShingleSet().end();
       originalIter++) {
    if (comparedProgram.getShingleSet().find(*originalIter) != comparedProgram.getShingleSet().end())
      coincidence++;
  }
  return coincidence * 100 / originalProgram.getShingleSet().size();      // TODO: прогрессивная формула
}

std::string ShingleChecker::hash_MD5(const std::string &key) {

  Poco::MD5Engine md5;
  Poco::DigestOutputStream ostr(md5);

  ostr << key;
  ostr.flush();

  return Poco::DigestEngine::digestToHex(md5.digest());
}

std::string ShingleChecker::hash_SHA1(const std::string &key) {

  std::string passphrase("anl!sfsd9!_3g2g?f73");

  //HMAC = Hash-based message authentication code
  Poco::HMACEngine<Poco::SHA1Engine> encoder(passphrase);
  encoder.update(key);

  return Poco::DigestEngine::digestToHex(encoder.digest());
}

void ShingleChecker::makeShingleSet(Program &originalProgram) {
  std::set<std::string> shingleSet;

  for (auto iter = originalProgram.getTokenSet().begin();
       iter <= originalProgram.getTokenSet().end() - K;
       iter++) {

    std::string shingle;
    for (auto innerIter = iter; innerIter < iter + K; innerIter++) {
      shingle += *innerIter;
    }

    std::string shingleHash = hash(shingle);
    shingleSet.insert(shingleHash);
  }
  originalProgram.setShingleSet(shingleSet);
}
int ShingleChecker::check(Program &originalProgram, Program &comparedProgram) {
  if (originalProgram.getShingleSet().empty()) {
    makeShingleSet(originalProgram);
  }
  if (comparedProgram.getShingleSet().empty()) {
    makeShingleSet(comparedProgram);
  }

  int coincidence = 0;

  for (auto originalIter = originalProgram.getShingleSet().begin();
       originalIter != originalProgram.getShingleSet().end();
       originalIter++) {
    if (comparedProgram.getShingleSet().find(*originalIter) != comparedProgram.getShingleSet().end())
      coincidence++;
  }
  return coincidence * 100 / originalProgram.getShingleSet().size();      // TODO: прогрессивная формула
}
