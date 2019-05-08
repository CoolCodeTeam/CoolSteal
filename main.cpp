

#include "lexUtils/LexerCpp.h"

int main(){
    LexerCpp lex = LexerCpp();
    Program program = Program("int HashFunc1(const string &str, int size){ int hash=0; int len = str.size(); for (int i=0; i< len; i++){ hash = (hash*661 + str[i])%size; } return hash; }", 1, "cpp");
    program.setNormalizeCode("#include <stdio.h> #include <stdlib.h> #include <string.h> #include <malloc.h> char char **s, int n{ int k,i,len = 0; for (i=0;i<n;i++) { len += strlen(*(s+i)); } char *result = (char *)malloc(len+1); result[0]='\0'; k=0; for (i=0;i<n;i++) { strcat(result,*(s+i)); k += strlen(*(s+i)); } printf("\%s",result); return result; } int main() { int n,j,n1,i; j=0; 1=0; n=1; i=0; scanf("%d", &n); getchar(); char *s[n],*buff = NULL; char c; for (j=0;j<n;j++){ n1=100; i=0; buff=(char *)malloc(100); while ((c=getchar())!='\n'){ if (i++>=n1){ buff = (char *)realloc(buff,n1+1); n1 ++;} *(buff+i-1)=c; } *(buff+i) ='\0'; s[j]=buff; } free(concat(s,n)); for (i=0;i<n;i++) free(s[i]); return 0; }");
    vector<Token> v = lex.getTokenSet(program);
    cout << v.size() << endl;
    for (int i=0; i<v.size(); i++){
        cout << v[i].getType() << " " << v[i].getData() << endl;
    }
}

//"int HashFunc1(const string &str, int size){ int hash=0; int len = str.size(); for (int i=0; i< len; i++){ hash = (hash*661 + str[i])%size; } return hash; }"
//" template <class T> class HashTable{ public: HashTable(); ~HashTable(); bool HasElem(const T& key); bool AddElem(const T& key); bool DeleteElem(const T& key); void Print(); private:float koef=0; vector<T> table; int size; int numberOfElems; void NewTable(); };"
//"#ifndef COOLSTEALNIGHT_TOKENTYPE_H #define COOLSTEALNIGHT_TOKENTYPE_H enum TokenType { KEYWORD, VARIABLE_TYPE, VALUE_TYPE, IDENTIFICATOR, OPERATOR, CYCLE, CONDITION };#endif //COOLSTEALNIGHT_TOKENTYPE_H"
//"#include <iostream> #include <cassert> #include <cstdlib> #include <cmath> using namespace std; struct Coord{ float x, y; Coord() = default; Coord(float x, float y): x(x), y(y){} float square(Coord* array, int len){ float square = ; int i=0; for (i=1; i<=len; i++) {if (i==len){ square+=(array[i-1].x - array[0].x)*(array[0].y + array[i-1].y)/2;} else square+=(array[i-1].x - array[i].x)*(array[i].y + array[i-1].y)/2; } square = fabs(square); return square; } int main(){ int n, i=0; cin >> n; auto *array = new Coord[n]; for (i=0; i<n; i++){ cin >> array[i].x >> array[i].y;} cout << square(array, n) << endl; delete [] array; return 0; }"
//"#include <stdio.h> #include <stdlib.h> #include <string.h> #include <malloc.h> char char **s, int n{ int k,i,len = 0; for (i=0;i<n;i++) { len += strlen(*(s+i)); } char *result = (char *)malloc(len+1); result[0]='\0'; k=0; for (i=0;i<n;i++) { strcat(result,*(s+i)); k += strlen(*(s+i)); } printf("%s",result); return result; } int main() { int n,j,n1,i; j=0; 1=0; n=1; i=0; scanf("%d", &n); getchar(); char *s[n],*buff = NULL; char c; for (j=0;j<n;j++){ n1=100; i=0; buff=(char *)malloc(100); while ((c=getchar())!='\n'){ if (i++>=n1){ buff = (char *)realloc(buff,n1+1); n1 ++;} *(buff+i-1)=c; } *(buff+i) ='\0'; s[j]=buff; } free(concat(s,n)); for (i=0;i<n;i++) free(s[i]); return 0; }"