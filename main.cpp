

#include "Normalizator/Normalizator.h"
#include "lexUtils/LexerCpp.h"
#include <gtest/gtest.h>

int main(int argc, char **argv) {

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
}

/*
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
 */




