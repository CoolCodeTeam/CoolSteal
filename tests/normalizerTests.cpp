//
// Created by anton on 06.05.19.
//

#include "../Normalizator/Normalizator.h"
#include "../lexUtils/LexerCpp.h"
#include "../methods/CheckLibary.h"
#include "../models/Program.h"
#include <gtest/gtest.h>
TEST(normalizer_tests, normalizer_test_1) {
  LexerCpp lex;
  Normalizator normalizator;
  Program firstProgram("#include<stdio.h>          \n");
  firstProgram.setNormalizeCode(normalizator.normalize(firstProgram));
  ASSERT_EQ(firstProgram.getNormalizeCode(), "#include<stdio.h> ");
}

TEST(normalizer_tests, normalizer_test_2) {
  LexerCpp lex;
  Normalizator normalizator;
  Program firstProgram("#include <stdio.h>\n"
                       "\n"
                       "int main(int argc, char **argv)\n"
                       "{\n"
                       "    int     n;\n"
                       "    scanf (\"%d\", &n); //считываем число   \n"
                       "    /*\n"
                       "    printf (\"%d \\n\", n);\n"
                       "     */\n"
                       "    //переписать вывод на экран\n"
                       "    return    0;\n"
                       "}");
  firstProgram.setNormalizeCode(normalizator.normalize(firstProgram));
  ASSERT_EQ(firstProgram.getNormalizeCode(),
            "#include <stdio.h> int main(int argc, char **argv) { int n; scanf "
            "(\"%d\", &n); return 0; }");
}

TEST(normalizer_tests, normalizer_test_3) {
  LexerCpp lex;
  Normalizator normalizator;
  Program firstProgram("    #include <stdio.h>\n"
                       "\n"
                       "#include     <stdlib.h>\n"
                       "\n"
                       "int main()\n //дописать программу\n"
                       "{\t"
                       "  /*   int a, b;\n"
                       "\t"
                       "    scanf(\"%d %d\", &a, &b);\n\n\n\n\n\n"
                       "    //long k[a][b], c[a], d[b];\n"
                       "    for (i=0; i<a; i++)\n"
                       "        for(j=0; j<b; j++)\n"
                       "            scanf(\"%ld\", &k[i][j]);  */"
                       "}");
  firstProgram.setNormalizeCode(normalizator.normalize(firstProgram));
  ASSERT_EQ(firstProgram.getNormalizeCode(),
            "#include <stdio.h> #include <stdlib.h> int main() { }");
}
