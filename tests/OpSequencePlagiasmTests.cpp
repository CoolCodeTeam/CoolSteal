//
// Created by alexis on 18.05.19.
//

#include "../Normalizator/Normalizator.h"
#include "../lexUtils/LexerCpp.h"
#include "../methods/CheckLibary.h"
#include "../models/Program.h"
#include <gtest/gtest.h>
TEST(op_seq_methods_tests, op_seq_plagiasm_test_1) {
  CheckLibary checkLibary;
  Normalizator normalizator;
  LexerCpp lex;
  Program firstProgram("bool is_Prime(int n){\n"
                       " if (n==1) return false;\n"
                       " for(int i = 2; i*i<=n;++i){\n"
                       " if (n%i==0)return false;\n"
                       " }\n"
                       " return true;\n"
                       "}");
  Program secondProgram("bool is_Prime(int n){\n"
                        " for(int i = 2; i<=sqrt(n);i++){\n"
                        " if (n%i==0)return false;\n"
                        " }\n"
                        " if (n!=1) return true;\n"
                        " else return false;\n"
                        "}");
  firstProgram.setLang("CPP");
  secondProgram.setLang("CPP");
  firstProgram.setNormalizeCode(normalizator.normalize(firstProgram));
  secondProgram.setNormalizeCode(normalizator.normalize(secondProgram));
  firstProgram.setTokenSet(lex.getTokens(firstProgram));
  secondProgram.setTokenSet(lex.getTokens(secondProgram));
  firstProgram.setOperatorSet(lex.getOpSet(firstProgram));
  secondProgram.setOperatorSet(lex.getOpSet(secondProgram));
  ASSERT_EQ(
      checkLibary.getOpSequencePlagiasmResult(firstProgram, secondProgram), 21);
}
