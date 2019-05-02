//
// Created by anton on 02.05.19.
//

#include "LevenstainChecker.h"
int LevenstainChecker::check(Program &originalProgram, const Program &comparedProgram) {
  int len1= originalProgram.getTokenSet().size();
  int len2= comparedProgram.getTokenSet().size();
  float levenstainDist = getEditDist(originalProgram.getTokenSet(),comparedProgram.getTokenSet(),len1,len2);
  float maxLen = std::max(len1,len2);
  return 100*(1-levenstainDist/maxLen);

}

int LevenstainChecker::check(Program &originalProgram, Program &comparedProgram) {
  int len1= originalProgram.getTokenSet().size();
  int len2= comparedProgram.getTokenSet().size();
  float levenstainDist = getEditDist(originalProgram.getTokenSet(),comparedProgram.getTokenSet(),len1,len2);
  float maxLen = std::max(len1,len2);
  return 100*(1-levenstainDist/maxLen);
}

int LevenstainChecker::getEditDist(std::string str1, std::string str2,int m,int n) {


  int dp[m+1][n+1];


  for (int i=0; i<=m; i++)
  {
    for (int j=0; j<=n; j++)
    {

      if (i==0)
        dp[i][j] = j;


      else if (j==0)
        dp[i][j] = i;


      else if (str1[i-1] == str2[j-1])
        dp[i][j] = dp[i-1][j-1];


      else
        dp[i][j] = 1 + min(dp[i][j-1],
                           dp[i-1][j],
                           dp[i-1][j-1]);
    }
  }
  int mem;
  return dp[m][n];

}
int LevenstainChecker::min(int x, int y, int z) {
  return std::min(std::min(x, y), z);
}

