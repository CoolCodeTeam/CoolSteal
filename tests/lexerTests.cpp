//
// Created by anton on 06.05.19.
//
#include "../Normalizator/Normalizator.h"
#include "../lexUtils/LexerCpp.h"
#include "../methods/CheckLibary.h"
#include "../models/Program.h"
#include <gtest/gtest.h>
TEST(lexer_tests, lexer_test_1) {
  LexerCpp lex;
  Normalizator normalizator;
  Program program("int length; long long\n");
  program.setLang("CPP");
  program.setNormalizeCode(normalizator.normalize(program));
  ASSERT_EQ(lex.getTokens(program), "1341");
}

TEST(lexer_tests, lexer_test_2) {
  LexerCpp lex;
  Normalizator normalizator;
  Program program("#include <stdio.h>\n");
  program.setLang("CPP");
  program.setNormalizeCode(normalizator.normalize(program));
  ASSERT_EQ(lex.getTokens(program), "02");
}

TEST(lexer_tests, lexer_test_3) {
  LexerCpp lex;
  Normalizator normalizator;
  Program program("#include <stdio.h>\n"
                  "using namespace std;\n"
                  "\n"
                  "template <class T>\n"
                  "struct BinaryNode{\n"
                  "    T val;\n"
                  "    BinaryNode<T>* left;\n"
                  "    BinaryNode<T>* right;\n"
                  "    BinaryNode() = default;\n"
                  "    BinaryNode(T i);\n"
                  "};\n"
                  "\n"
                  "template <class T>\n"
                  "BinaryNode<T>::BinaryNode(T i){\n"
                  "    val=i;\n"
                  "    left=right= nullptr;\n"
                  "}");
  program.setLang("CPP");
  program.setNormalizeCode(normalizator.normalize(program));
  ASSERT_EQ(lex.getTokens(program), "020034040340343343434434343443434440434334"
                                    "444040343434434334434343434044");
}

TEST(lexer_tests, lexer_test_4) {
  LexerCpp lex;
  Normalizator normalizator;
  Program program(";*<<=>>=*;");
  program.setLang("CPP");
  program.setNormalizeCode(normalizator.normalize(program));
  ASSERT_EQ(lex.getTokens(program), "444444");
}