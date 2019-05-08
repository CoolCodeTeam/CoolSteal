//
// Created by anton on 05.05.19.
//

#include "../Normalizator/Normalizator.h"
#include "../lexUtils/LexerCpp.h"
#include "../methods/CheckLibary.h"
#include "../models/Program.h"
#include <gtest/gtest.h>

TEST(methods_tests, shingle_test_1) {
  CheckLibary checkLibary;
  Normalizator normalizator;
  LexerCpp lex;
  Program firstProgram("#include<stdio.h>\n"
                       "int main() {\n"
                       " int x=10;\n"
                       " int y=25;\n"
                       " int z=x+y;\n"
                       " printf(z);\n"
                       "}");
  Program secondProgram("#include<stdio.h>\n"
                        "int main() {\n"
                        " int a=10;\n"
                        " int b=25;\n"
                        " int c=a+b;\n"
                        " printf(c);\n"
                        "}");
  firstProgram.setLang("CPP");
  secondProgram.setLang("CPP");
  firstProgram.setNormalizeCode(normalizator.normalize(firstProgram));
  secondProgram.setNormalizeCode(normalizator.normalize(secondProgram));
  firstProgram.setTokenSet(lex.getTokens(firstProgram));
  secondProgram.setTokenSet(lex.getTokens(secondProgram));
  ASSERT_EQ(checkLibary.getShingleResult(firstProgram, secondProgram), 100);
}

TEST(methods_tests, shingle_test_2) {
  CheckLibary checkLibary;
  Normalizator normalizator;
  LexerCpp lex;
  Program firstProgram("for (int i = 1; i < n; i++){\n"
                       " x =arr[i].x, y =arr[i].y;\n"
                       " S +=(yl+y) /2* (x - xl);\n"
                       "}");
  Program secondProgram("for (int i = 1; i < n; i++){\n"
                        " x = source[i].x, y = source[i].y;\n"
                        " S += midline(yl, y) * (x - xl);\n"
                        "}");
  firstProgram.setLang("CPP");
  secondProgram.setLang("CPP");
  firstProgram.setNormalizeCode(normalizator.normalize(firstProgram));
  secondProgram.setNormalizeCode(normalizator.normalize(secondProgram));
  firstProgram.setTokenSet(lex.getTokens(firstProgram));
  secondProgram.setTokenSet(lex.getTokens(secondProgram));
  ASSERT_EQ(checkLibary.getShingleResult(firstProgram, secondProgram), 57);
}

TEST(methods_tests, shingle_test_3) {
  CheckLibary checkLibary;
  Normalizator normalizator;
  LexerCpp lex;
  Program firstProgram("#include <stdio.h>\n"
                       "#include <stdlib.h>\n"
                       "int main()\n"
                       "{\n"
                       " long n, x, result = 0, i, d;\n"
                       " scanf (\"%ld%ld\", &n, &x);\n"
                       " long a[n];\n"
                       " for (i = 0; i <= n; i++) {\n"
                       " scanf (\"%ld\", &(a[i]));\n"
                       " result = result * x + a[i];\n"
                       " }\n"
                       " printf (\"%ld\\n\", result);\n"
                       " if (n==0) {\n"
                       " printf (\"0\");\n"
                       " return 0;\n"
                       " }\n"
                       " if (n==1) {\n"
                       " printf (\"%d\", a[0]);\n"
                       " return 0;\n"
                       " }\n"
                       " long proiz = 0;\n"
                       " long h=n;\n"
                       " for (i = 0; i < h; i++)\n"
                       " proiz = proiz * x + a[i] * (n--);\n"
                       " printf (\"%ld\", proiz);\n"
                       " return 0;\n"
                       "}");
  Program secondProgram("#include <stdio.h>\n"
                        "#include <stdlib.h>\n"
                        "//Полином\n"
                        "int main()\n"
                        "{long n, x, result = 0, i, d;\n"
                        " scanf (\"%ld%ld\", &n, &x);\n"
                        " long a[n];\n"
                        " for (i = 0; i <= n; i++) { //Ввод элементов\n"
                        " scanf (\"%ld\", &(a[i]));\n"
                        " result = result * x + a[i];\n"
                        " }\n"
                        " printf (\"%ld\\n\", result);\n"
                        " if (n==0) {\n"
                        " printf (\"0\");\n"
                        " return 0;\n"
                        " }\n"
                        " if (n==1) {\n"
                        " printf (\"%d\", a[0]);\n"
                        " return 0;\n"
                        " }\n"
                        " long proiz = 0;\n"
                        " long h=n;\n"
                        " for (i = 0; i < h; i++)\n"
                        " proiz = proiz * x + a[i] * (n--);\n"
                        " printf (\"%ld\", proiz);\n"
                        " return 0;\n"
                        "}");
  firstProgram.setLang("CPP");
  secondProgram.setLang("CPP");
  firstProgram.setNormalizeCode(normalizator.normalize(firstProgram));
  secondProgram.setNormalizeCode(normalizator.normalize(secondProgram));
  firstProgram.setTokenSet(lex.getTokens(firstProgram));
  secondProgram.setTokenSet(lex.getTokens(secondProgram));
  ASSERT_EQ(checkLibary.getShingleResult(firstProgram, secondProgram), 86);
}

TEST(methods_tests, shingle_test_4) {
  CheckLibary checkLibary;
  Normalizator normalizator;
  LexerCpp lex;
  Program firstProgram(
      "#include <stdio.h>\n"
      "#include <stdlib.h>\n"
      "#include <math.h>\n"
      "const long long one = 1;\n"
      "#define GETBIT(x, pos) ( ((x) & ( one << (pos) )) !=0 )\n"
      "#define GETLENGTH(x) ( (x == 0) ? 1 : (int) floorl(log2l(x + 0.5)) )\n"
      "int main()\n"
      "{\n"
      " long long a, b, k;\n"
      " scanf(\"%lld%lld%lld\", &a, &b, &k);\n"
      " long long sum = 0;\n"
      " int i;\n"
      " for (i = GETLENGTH(b); i >= 0; i--)\n"
      " {\n"
      " sum = (sum % k) * 2 + (a % k) * (GETBIT(b, i));\n"
      " }\n"
      " sum = sum % k;\n"
      " printf(\"%lld\\n\", sum);\n"
      " return 0;\n"
      "}");
  Program secondProgram(
      "#include <stdio.h>\n"
      "#include <stdlib.h>\n"
      "#include <math.h>\n"
      "const long long one = 1;\n"
      "#define GETBIT(x, pos) ( ((x) & ( one << (pos) )) !=0 )\n"
      "#define GETLENGTH(x) ( (x == 0) ? 1 : (int) floorl(log2l(x + 0.5)) )\n"
      "int main(){\n"
      " long a, b, k;\n"
      " scanf(\"%ld%ld%ld\", &a, &b, &k);\n"
      " long sum = 0;\n"
      " int i;\n"
      " for (i = GETLENGTH(b); i >= 0; i--) {\n"
      " sum = (sum % k) * 2 + (a % k) * (GETBIT(b, i));\n"
      " }\n"
      " sum = sum % k;\n"
      " printf(\"%ld\\n\", sum);\n"
      " return 0;\n"
      "}");

  firstProgram.setLang("CPP");
  secondProgram.setLang("CPP");
  firstProgram.setNormalizeCode(normalizator.normalize(firstProgram));
  secondProgram.setNormalizeCode(normalizator.normalize(secondProgram));
  firstProgram.setTokenSet(lex.getTokens(firstProgram));
  secondProgram.setTokenSet(lex.getTokens(secondProgram));
  ASSERT_EQ(checkLibary.getShingleResult(firstProgram, secondProgram), 66);
}
TEST(methods_tests, shingle_test_5) {
  CheckLibary checkLibary;
  Normalizator normalizator;
  LexerCpp lex;
  Program firstProgram("#include<stdio.h>\n"
                       "#include<stdlib.h>\n"
                       "#include<string.h>\n"
                       "int strdiff(char *a, char *b) {\n"
                       " long i, j, g, f;\n"
                       " if (strlen(a) >= strlen(b))\n"
                       " f = strlen(b);\n"
                       " else f = strlen(a);\n"
                       " if ((strlen(a) != 0) && (strlen(b) != 0)) {\n"
                       " for (i = 0; i < f+1; i++){\n"
                       " for (j = 0; j < 8; j++)\n"
                       " if ((((a[i]) >> (j)) & 1) != (((b[i]) >> (j)) & 1)){\n"
                       " g = i * 8 + j;\n"
                       " return g;\n"
                       " }\n"
                       " }\n"
                       " }\n"
                       " else return 0;\n"
                       " return -1;\n"
                       "}");
  Program secondProgram("struct Elem *searchlist(struct Elem *list, int k){\n"
                        " struct Elem *p = list;\n"
                        " while (p){\n"
                        " if (p->tag == INTEGER && p->value.i == k)\n"
                        " return p;\n"
                        " if (p->tag == LIST){\n"
                        " struct Elem *tp = searchlist(p->value.list, k);\n"
                        " if (tp) return tp;\n"
                        " }\n"
                        " p = p->tail;\n"
                        " }\n"
                        " return p;\n"
                        "}");
  firstProgram.setLang("CPP");
  secondProgram.setLang("CPP");
  firstProgram.setNormalizeCode(normalizator.normalize(firstProgram));
  secondProgram.setNormalizeCode(normalizator.normalize(secondProgram));
  firstProgram.setTokenSet(lex.getTokens(firstProgram));
  secondProgram.setTokenSet(lex.getTokens(secondProgram));
  ASSERT_EQ(checkLibary.getShingleResult(firstProgram, secondProgram), 0);
}

TEST(methods_tests, shingle_test_6) {
  CheckLibary checkLibary;
  Normalizator normalizator;
  LexerCpp lex;
  Program firstProgram("#include<stdio.h>\n"
                       "int main() {\n"
                       " int x=10;\n"
                       " int y=25;\n"
                       " int z=x+y;\n"
                       " printf(z);\n"
                       "}");
  Program secondProgram("#include<stdio.h>\n"
                        "int main() {\n"
                        " int x=10;\n"
                        " int y=25;\n"
                        " int z=x+y;\n"
                        " printf(z);\n"
                        "}");
  firstProgram.setLang("CPP");
  secondProgram.setLang("CPP");
  firstProgram.setNormalizeCode(normalizator.normalize(firstProgram));
  secondProgram.setNormalizeCode(normalizator.normalize(secondProgram));
  firstProgram.setTokenSet(lex.getTokens(firstProgram));
  secondProgram.setTokenSet(lex.getTokens(secondProgram));
  ASSERT_EQ(checkLibary.getShingleResult(firstProgram, secondProgram), 100);
}
