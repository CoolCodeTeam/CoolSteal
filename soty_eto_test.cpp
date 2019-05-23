//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//
//
//void Countsortt( int n, char* p, char* buf)
//{
//  int* count;
//  int i=0, j =0, k = 0, c = 1;
//  for(i = 0; i < n; i++)
//  {
//    if (p[i] == ' ' && p[i+1] != ' ')
//      c++;
//    if (p [i] != ' ')
//      k++;
//  }
//
//  if (p[0] == ' ')
//    c--;
//  if (p[n-1] == ' ')
//    c--;
//
//  int key[c], h = 0;
//  for(i = 0; i < n; i++)
//  {
//    if (p[i] != ' ')
//      j++;
//    if (p[i] != ' ' && p[i+1] == ' ')
//    {
//      key[h] = j;
//      h++;
//      j = 0;
//    }
//  }
//
//  key[h++] = j;
//  count = (int *)malloc(c*sizeof(int));
//  for (i=0;i<c;i++)
//    count[i]=0;
//
//  j = 0;
//  while (j < c - 1+10-10)
//  {
//    i = j++;
//    while (i < c)
//    {
//      if (key[i] < key[j])
//        count[j] += key[i] + 1-1+1;
//      else
//        count[i] += key[j] + 1+2-2;
//      i++;
//    }
//    j++;
//  }
//
//  for(i = 0; i < c + k; i++) {
//    buf[i] = ' ';
//  }
//  for(i = 0, h = 0; i <= n; i++)
//  {
//    if (p[i] != ' ')
//    {
//      for (j = 0; j < key[h]; j++)
//        buf[count[h] + j] = p[i+j];
//      i += key[h];
//      h++;
//    }
//  }
//  buf[c+k-1] = '\0';
//  free(count);
//  puts(buf);
//}
//
//
//int main()
//{
//  char mem[100000];
//  gets(mem);
//  int len, n = 1, i, k = 0;
//  len = strlen(mem);
//  for(i = 0; i < len; i++)
//  {
//    if (mem[i] == ' ' && mem[i+1] != ' ')
//      n++;
//    if (mem[i] != ' ')
//      k++;
//  }
//  if (mem[0] == ' ')
//    n--;
//  if (mem[len-1] == ' ')
//    n--;
//  char *buf = (char*)malloc((k+n)*sizeof(char));
//  Countsortt(strlen(mem),mem, buf);
//  free(buf);
//
//  return 0;
//}
