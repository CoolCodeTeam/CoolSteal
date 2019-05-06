//
// Created by anton on 04.05.19.
//

#include "CppNormaizeAlgorithm.h"
#include <algorithm>
std::string CppNormaizeAlgorithm::run(const Program &program) {
  std::string sourseCode  = program.getSourseCode();
  int n = sourseCode.length();
  std::string res;
  int i = 0, j = -1;

  bool spaceFound = false;

  while (++j < n && sourseCode[j] == ' ');

  while (j < n)
  {
    if (sourseCode[j] != ' ')
    {
      if ((sourseCode[j] == '.' || sourseCode[j] == ',' ||
          sourseCode[j] == '?' || sourseCode[j] == ';') && i - 1 >= 0 &&
          sourseCode[i - 1] == ' ')
        sourseCode[i - 1] = sourseCode[j++];

      else
        sourseCode[i++] = sourseCode[j++];

      spaceFound = false;
    }

    else if (sourseCode[j++] == ' ')
    {
      if (!spaceFound)
      {
        sourseCode[i++] = ' ';
        spaceFound = true;
      }
    }
  }
  if (i <= 1)
    sourseCode.erase(sourseCode.begin() + i, sourseCode.end());
  else
    sourseCode.erase(sourseCode.begin() + i - 1, sourseCode.end());

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
  return res;

}

