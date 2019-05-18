

#include "Normalizator/Normalizator.h"
#include "lexUtils/LexerCpp.h"
#include "methods/CheckLibary.h"
#include <gtest/gtest.h>

//int main(int argc, char **argv) {
//
//  CheckLibary checkLibary;
//  Normalizator normalizator;
//  LexerCpp lex;
//  Program firstProgram("bool is_Prime(int n){\n"
//                       " if (n==1) return false;\n"
//                       " for(int i = 2; i*i<=n;++i){\n"
//                       " if (n%i==0)return false;\n"
//                       " }\n"
//                       " return true;\n"
//                       "}");
//  Program secondProgram("bool is_Prime(int n){\n"
//                        " for(int i = 2; i<=sqrt(n);i++){\n"
//                        " if (n%i==0)return false;\n"
//                        " }\n"
//                        " if (n!=1) return true;\n"
//                        " else return false;\n"
//                        "}");
//  firstProgram.setLang("CPP");
//  secondProgram.setLang("CPP");
//  firstProgram.setNormalizeCode(normalizator.normalize(firstProgram));
//  secondProgram.setNormalizeCode(normalizator.normalize(secondProgram));
//  firstProgram.setTokenSet(lex.getTokens(firstProgram));
//  secondProgram.setTokenSet(lex.getTokens(secondProgram));
//  firstProgram.setOperatorSet(lex.getOpSet(firstProgram));
//  secondProgram.setOperatorSet(lex.getOpSet(secondProgram));
//  // cout << firstProgram.getTokenSet() << endl;
//  // cout << secondProgram.getTokenSet() << endl;
//  // cout << firstProgram.getOperatorSet()[0].getData() <<
//  // firstProgram.getOperatorSet()[1].getData() << endl; cout <<
//  // secondProgram.getTokenSet() << endl;
//  cout << " ?"
//       << checkLibary.getOpSequencePlagiasmResult(firstProgram, secondProgram)
//       << endl;
//  testing::InitGoogleTest(&argc, argv);
//  RUN_ALL_TESTS();
//}


#include "CoolStealServerApp.h"
#include <gtest/gtest.h>
#include <iostream>

int main(int argc, char** argv) {
     CoolStealServerApp app;
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return app.run(argc, argv);
    return 0;
}


/*int main(int argc, char **argv) {

  Program program(";*<<=>>=*;");
  LexerCpp lex = LexerCpp();
  program.setLang("CPP");
  Normalizator normalizator;
  cout << normalizator.normalize(program) << endl;
  program.setNormalizeCode(normalizator.normalize(program));
  vector<Token> v = lex.getTokenSet(program);
  cout << v.size() << endl;
  for (int i = 0; i < v.size(); i++) {
    cout << v[i].getType() << " " << v[i].getData() << endl;
  }
  testing::InitGoogleTest(&argc, argv);
  RUN_ALL_TESTS();
}*/
