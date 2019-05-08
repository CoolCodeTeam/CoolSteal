//
// Created by anton on 04.05.19.
//

#include "CppNormaizeAlgorithm.h"
#include <algorithm>
std::string CppNormaizeAlgorithm::run(const Program &program) {
  std::string sourseCode  = program.getSourseCode();
  int n = sourseCode.length();
  std::string res;

  bool singleCommentFlag = false;
  bool multiplyCommentFlag = false;

  n = sourseCode.length();
  for (int i=0; i<n; i++)
  {
    if (singleCommentFlag && sourseCode[i] == '\n')
      singleCommentFlag = false;

    else if  (multiplyCommentFlag && sourseCode[i] == '*' && sourseCode[i+1] == '/')
      multiplyCommentFlag = false,  i++;

    else if (singleCommentFlag || multiplyCommentFlag)
      continue;

    else if (sourseCode[i] == '/' && sourseCode[i+1] == '/')
      singleCommentFlag = true, i++;
    else if (sourseCode[i] == '/' && sourseCode[i+1] == '*')
      multiplyCommentFlag = true,  i++;
    else  res += sourseCode[i];
  }
  for(int j=0; j< res.length(); j++) if (res[j] == '\n' || res[j] == '\r' || res[j] == '\t') res[j]=' ';
    int i = 0, j = -1;

    bool spaceFound = false;

    while (++j < n && res[j] == ' ');

    while (j < n) {
        if (res[j] != ' ') {
            if ((res[j] == '.' || res[j] == ',' ||
                 res[j] == '?' || res[j] == ';') && i - 1 >= 0 &&
                res[i - 1] == ' ')
                res[i - 1] = res[j++];

            else
                res[i++] = res[j++];

            spaceFound = false;
        } else if (res[j++] == ' ') {
            if (!spaceFound) {
                res[i++] = ' ';
                spaceFound = true;
            }
        }
    }
    res.erase(res.begin() + i, res.end());
  return res;

}

