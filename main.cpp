

#include "lexUtils/LexerCpp.h"

int main(){
    LexerCpp lex = LexerCpp();
    Program program = Program("int HashFunc1(const string &str, int size){ int hash=0; int len = str.size(); for (int i=0; i< len; i++){ hash = (hash*661 + str[i])%size; } return hash; }", 1, "cpp");
    program.setNormalizeCode("#include <iostream> #include <cassert> #include <cstdlib> #include <cmath> using namespace std; struct Coord{ float x, y; Coord() = default; Coord(float x, float y): x(x), y(y){} float square(Coord* array, int len){ float square = ; int i=0; for (i=1; i<=len; i++) {if (i==len){ square+=(array[i-1].x - array[0].x)*(array[0].y + array[i-1].y)/2;} else square+=(array[i-1].x - array[i].x)*(array[i].y + array[i-1].y)/2; } square = fabs(square); return square; } int main(){ int n, i=0; cin >> n; auto *array = new Coord[n]; for (i=0; i<n; i++){ cin >> array[i].x >> array[i].y;} cout << square(array, n) << endl; delete [] array; return 0; }");
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