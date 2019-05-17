#include "../models/PlagiasmResult.h"
#include "../models/Program.h"

class CheckLibaryInterface {
public:
  virtual PlagiasmResult getSimilaity(Program &originalProgram,
                                      const Program &comparedProgram) = 0;
  virtual PlagiasmResult getSimilaity(Program &originalProgram,
                                      Program &comparedProgram) = 0;
  virtual int getShingleResult(Program &originalProgram,
                               const Program &comparedProgram) = 0;
  virtual int getShingleResult(Program &originalProgram,
                               Program &comparedProgram) = 0;
  virtual int getLevenstainResult(Program &originalProgram,
                                  const Program &comparedProgram) = 0;
  virtual int getOpSequencePlagiasmResult(Program &originalProgram,
                                          Program &comparedProgram) = 0;
  virtual int getOperatorPlagiasmResult(Program &originalProgram,
                                        Program &comparedProgram) = 0;
};