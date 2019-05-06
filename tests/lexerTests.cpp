//
// Created by anton on 06.05.19.
//
#include <gtest/gtest.h>
#include "../models/Program.h"
#include "../Normalizator/Normalizator.h"
#include "../lexUtils/LexerCpp.h"
#include "../methods/CheckLibary.h"
TEST(lexer_tests, lexer_test_1) {
  LexerCpp lex;
  Normalizator normalizator;
  Program firstProgram("#include<stdio.h>\n");
  firstProgram.setNormalizeCode(normalizator.normalize(firstProgram));
  ASSERT_EQ(lex.getTokens(firstProgram), "02");
}