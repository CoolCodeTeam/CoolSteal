//
// Created by anton on 05.05.19.
//

#include "../Normalizator/Normalizator.h"
#include "../lexUtils/LexerCpp.h"
#include "../methods/CheckLibary.h"
#include "../models/Program.h"
#include <gtest/gtest.h>

TEST(levenstain_methods_tests, levenstain_test_1) {
  CheckLibary checkLibary;
  Normalizator normalizator;
  LexerCpp lex;
  Program firstProgram("#include <iostream>\n"
                       "using namespace std;\n"
                       "void bubble(int* arr, int size){\n"
                       " for(int i = size = 1; i >= 0; i--){\n"
                       " for(int j = 0; j < i; j++){\n"
                       " if (arr[j] > arr[j+1]){\n"
                       " int tmp = arr[j];\n"
                       " arr[j] = arr[j+1];\n"
                       " arr[j+1] = tmp;\n"
                       " }\n"
                       " }\n"
                       " }\n"
                       "}\n"
                       "int main(){\n"
                       " int arr[]={3,2,1,5,4,22,31,0,-3,-5,1,3};\n"
                       " int size = 12;\n"
                       " bubble(arr, size);\n"
                       " for (int i = 0; i < size; ++i){\n"
                       " cout << arr[i] << \" \";\n"
                       " }\n"
                       " return 0;\n"
                       "}");
  Program secondProgram("#include <iostream>\n"
                        "using namespace std;\n"
                        "void bubble(double* arr, int size){\n"
                        " int i = size;\n"
                        " while(i >= 0){\n"
                        " for(int j = 0; j < i; j++){\n"
                        " if (arr[j] > arr[j+1]){\n"
                        " int tmp = arr[j];\n"
                        " arr[j] = arr[j+1];\n"
                        " arr[j+1] = tmp;\n"
                        " }\n"
                        " }\n"
                        " i--;\n"
                        " }\n"
                        "}\n"
                        "int main(){\n"
                        " int size, i;\n"
                        " double arr[]={3,2,1,5,4,22,31,0,-3,-5,1,3};\n"
                        " size = 12;\n"
                        " i = 0;\n"
                        " bubble(arr, size);\n"
                        " for (int i = 0; i < size; ++i){\n"
                        " cout << arr[i] << \" \";\n"
                        " }\n"
                        " return 0;\n"
                        "}");
  firstProgram.setLang("CPP");
  secondProgram.setLang("CPP");
  firstProgram.setNormalizeCode(normalizator.normalize(firstProgram));
  secondProgram.setNormalizeCode(normalizator.normalize(secondProgram));
  firstProgram.setTokenSet(lex.getTokens(firstProgram));
  secondProgram.setTokenSet(lex.getTokens(secondProgram));
  ASSERT_EQ(checkLibary.getLevenstainResult(firstProgram, secondProgram), 88);
}

TEST(levenstain_methods_tests, levenstain_test_2) {
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
                        " int a=5+5;\n"
                        " int b=30-5;\n"
                        " int c=a+b;\n"
                        " printf(c);\n"
                        "}");
  firstProgram.setLang("CPP");
  secondProgram.setLang("CPP");
  firstProgram.setNormalizeCode(normalizator.normalize(firstProgram));
  secondProgram.setNormalizeCode(normalizator.normalize(secondProgram));
  firstProgram.setTokenSet(lex.getTokens(firstProgram));
  secondProgram.setTokenSet(lex.getTokens(secondProgram));
  ASSERT_EQ(checkLibary.getLevenstainResult(firstProgram, secondProgram), 89);
}

TEST(levenstain_methods_tests, levenstain_test_3) {
  CheckLibary checkLibary;
  Normalizator normalizator;
  LexerCpp lex;
  Program firstProgram("#include <stdio.h>\n"
                       "#include <stdlib.h>\n"
                       "#include <math.h>\n"
                       "int main()\n"
                       "{\n"
                       " int n, m, b, b1, j, i, k=0;\n"
                       " unsigned long c=0, c1=0, c2;\n"
                       " scanf (\"%d\", &n);\n"
                       " for (i=0; i< n; i++) {\n"
                       " scanf (\"%d\", &b);\n"
                       " c += pow (2, b);\n"
                       " }\n"
                       " scanf (\"%d\", &m);\n"
                       " for (i=0; i< m; i++){\n"
                       " scanf (\"%d\", &b1);\n"
                       " c1 += pow (2, b1);\n"
                       " }\n"
                       " c2 = c1 & c;\n"
                       " for (i=0; i < 32 ;i++, k++) {\n"
                       " if (c2&(1<<i)) printf(\"%d \", i);\n"
                       " }\n"
                       " return 0;\n"
                       "}");
  Program secondProgram("#include <stdio.h>\n"
                        "#include <stdlib.h>\n"
                        "#include <math.h>\n"
                        "int main()\n"
                        "{\n"
                        " int n, m, b, b1, j, i, k=0;\n"
                        " unsigned long c=c1=0, c2;\n"
                        " scanf (\"%d\", &n);\n"
                        " for (i=0; i< n; ++i) {\n"
                        " scanf (\"%d\", &b);\n"
                        " c += pow (2, b);\n"
                        " }\n"
                        " scanf (\"%d\", &m);\n"
                        " for (i=0; i< m; ++i){\n"
                        " scanf (\"%d\", &b1);\n"
                        " c1 += pow (2, b1);\n"
                        " }\n"
                        " c2 = c1 & c;\n"
                        " for (i=0; i < 32 ;++i, ++k) {\n"
                        " if (c2&(1<<i)) printf(\"%d \", i);\n"
                        " }\n"
                        " return 0;\n"
                        "}");
  firstProgram.setLang("cpp");
  secondProgram.setLang("cpp");
  firstProgram.setNormalizeCode(normalizator.normalize(firstProgram));
  secondProgram.setNormalizeCode(normalizator.normalize(secondProgram));
  firstProgram.setTokenSet(lex.getTokens(firstProgram));
  secondProgram.setTokenSet(lex.getTokens(secondProgram));
  ASSERT_EQ(checkLibary.getLevenstainResult(firstProgram, secondProgram), 94);
}

TEST(levenstain_methods_tests, levenstain_test_4) {
  CheckLibary checkLibary;
  Normalizator normalizator;
  LexerCpp lex;
  Program firstProgram("#include<stdio.h>\n"
                       "#include<stdlib.h>\n"
                       "#include<string.h>\n"
                       "\n"
                       "char *concat(char** s, int n){\n"
                       " int i, l = 0;\n"
                       " char *res;\n"
                       " for (i = 0; i < n; i++) {\n"
                       " gets(s[i]);\n"
                       " l += strnlen(s[i], 50);\n"
                       " }\n"
                       " res = (char *)malloc((l+1)*sizeof(char));\n"
                       " res[0] = 0;\n"
                       " for (i = 0; i < n; i++)\n"
                       " strncat(res, s[i], l);\n"
                       " return res;\n"
                       "}\n"
                       "int main(){\n"
                       " char **s, *res;\n"
                       " int i, n;\n"
                       " scanf(\"%d\\n\",&n);\n"
                       " s=(char **)malloc(n*sizeof(char*));\n"
                       " for (i=0;i<n;i++)\n"
                       " s[i]=(char *)malloc(50*sizeof(char));\n"
                       " res = concat(s,n);\n"
                       " printf(\"%s\\n\", res);\n"
                       " for (i = 0; i < n; i++)\n"
                       " free(s[i]);\n"
                       " free(res);\n"
                       " free(s);\n"
                       " return 0;\n"
                       "}");
  Program secondProgram("#include<stdio.h>\n"
                        "#include<stdlib.h>\n"
                        "#include<string.h>\n"
                        " //Конкатенация строк\n"
                        "char *concat(char** s, int n){\n"
                        " int i, l = 0;\n"
                        " char *res;\n"
                        " for (i = 0; i < n; i++) {\n"
                        " gets(s[i]);\n"
                        " l += strnlen(s[i], 50);\n"
                        " }\n"
                        " res = (char *)malloc((l+1)*sizeof(char));\n"
                        " res[0] = 0;\n"
                        " for (i = 0; i < n; i++)\n"
                        " strncat(res, s[i], l);\n"
                        " return res;\n"
                        "}\n"
                        "int main(){\n"
                        " char **s, *res;\n"
                        " int i, n;\n"
                        " scanf(«%d\\n\",&n); //ввод кол-ства строк\n"
                        " s=(char **)malloc(n*sizeof(char*));\n"
                        " for (i=0;i<n;i++)\n"
                        " s[i]=(char *)malloc(50*sizeof(char));\n"
                        " res = concat(s,n);\n"
                        " printf(\"%s\\n\", res);\n"
                        " for (i = 0; i < n; i++)\n"
                        " free(s[i]);\n"
                        " free(res);\n"
                        " free(s);\n"
                        " return 0;\n"
                        "}");
  firstProgram.setLang("CPP");
  secondProgram.setLang("CPP");
  firstProgram.setNormalizeCode(normalizator.normalize(firstProgram));
  secondProgram.setNormalizeCode(normalizator.normalize(secondProgram));
  firstProgram.setTokenSet(lex.getTokens(firstProgram));
  secondProgram.setTokenSet(lex.getTokens(secondProgram));
  ASSERT_EQ(checkLibary.getLevenstainResult(firstProgram, secondProgram),
            100); //?????????
}

TEST(levenstain_methods_tests, levenstain_test_5) {
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
  firstProgram.setLang("cpp");
  secondProgram.setLang("cpp");
  firstProgram.setNormalizeCode(normalizator.normalize(firstProgram));
  secondProgram.setNormalizeCode(normalizator.normalize(secondProgram));
  firstProgram.setTokenSet(lex.getTokens(firstProgram));
  secondProgram.setTokenSet(lex.getTokens(secondProgram));
  ASSERT_EQ(checkLibary.getLevenstainResult(firstProgram, secondProgram), 97);
}
