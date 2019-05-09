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
  Program firstProgram("int length; long long\n");
  firstProgram.setLang("CPP");
  firstProgram.setNormalizeCode(normalizator.normalize(firstProgram));
  ASSERT_EQ(lex.getTokens(firstProgram), "1341");
}

TEST(lexer_tests, lexer_test_2) {
  LexerCpp lex;
  Normalizator normalizator;
  Program firstProgram("#include <stdio.h>\n");
  firstProgram.setLang("CPP");
  firstProgram.setNormalizeCode(normalizator.normalize(firstProgram));
  ASSERT_EQ(lex.getTokens(firstProgram), "02");
}

/*
TEST(lexer_tests, lexer_test_3) {
    LexerCpp lex;
    Normalizator normalizator;
    Program firstProgram("#include <stdio.h>\n"
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
    firstProgram.setLang("CPP");
    firstProgram.setNormalizeCode(normalizator.normalize(firstProgram));
    ASSERT_EQ(lex.getTokens(firstProgram), "02");
}
*/