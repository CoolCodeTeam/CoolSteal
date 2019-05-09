//
// Created by alexis on 02.05.19.
//

#include "CKeyWords.h"
const string cKW[] = {"alignas",      "alignof",
                      "and",          "and_eq",
                      "asm",          "auto",
                      "bitand",       "bool",
                      "break",        "case",
                      "catch",        "char",
                      "char16_t",     "char32_t",
                      "char",         "class",
                      "compl",        "const",
                      "constexpr",    "const_cast",
                      "continue",     "decltype",
                      "default",      "delete",
                      "do",           "double",
                      "dynamic_cast", "else",
                      "enum",         "explicit",
                      "export",       "extern",
                      "false",        "final",
                      "float",        "for",
                      "friend",       "goto",
                      "if",           "inline",
                      "int",          "long",
                      "mutable",      "namespace",
                      "new",          "noexcept",
                      "not",          "not_eq",
                      "nullptr",      "operator",
                      "or",           "or_eq",
                      "override",     "private",
                      "protected",    "public",
                      "register",     "reinterpret_cast",
                      "return",       "short",
                      "signed",       "sizeof",
                      "static",       "static_assert",
                      "static_cast",  "struct",
                      "switch",       "template",
                      "this",         "thread_local",
                      "throw",        "true",
                      "try",          "typedef",
                      "typeid",       "typename",
                      "union",        "unsigned",
                      "using",        "virtual",
                      "void",         "volatile",
                      "wchar_t",      "while",
                      "xor",          "xor_eq"};

const string cKWDirectives[] = {"#define", "#elif",    "#else",
                                "#endif",  "#if",      "#ifdef",
                                "#ifndef", "#include", "#undef"};

CKeyWords::CKeyWords() {
  for (int i = 0; i < end(cKW) - begin(cKW); i++)
    keyWords.insert(cKW[i]);
  for (int i = 0; i < end(cKWDirectives) - begin(cKWDirectives); i++)
    keyWordsDir.insert(cKWDirectives[i]);
}

bool CKeyWords::isToken(const string &string) {
  for (int i = 0; i < keyWords.size(); i++) {
    if (keyWords.count(string) > 0)
      return true;
  };
  for (int i = 0; i < keyWordsDir.size(); i++) {
    if (keyWordsDir.count(string) > 0)
      return true;
  };
}

bool CKeyWords::isDirective(const string &string) {
  for (int i = 0; i < keyWordsDir.size(); i++) {
    if (keyWordsDir.count(string) > 0)
      return true;
  };
}
