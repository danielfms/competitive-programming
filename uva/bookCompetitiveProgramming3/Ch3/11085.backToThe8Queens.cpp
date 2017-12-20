#include <bits/stdc++.h>
using namespace std;
int rows[8];
int in[8];
bool valido(int r, int c){
    //Validar con todas las posiciones 
    //halladas es decir hasta c
    // i es la columna de rows
    for(int i = 0; i < c; i++){
        //Comprobar las diagonales
        if(abs(r - rows[i]) == abs(c - i)){
            return false;
        }
        if(rows[i] == r){
            return false;
        }
    }
    return true;
}
int backtracking(int c){
    //Se encontro una solucion retorno el valor
    if(c >= 8){
        return 0;
    }
    int oo = 10000000;
    for(int r = 0; r < 8; r++){
        if(valido(r, c)){
            rows[c] = r;
            oo = min(oo, r == in[c] ? backtracking(c + 1) : 1 + backtracking(c + 1));
        }
    }
    return oo;
}

void split(string s){
    stringstream ss(s);
    int token;
    int i = 0;
    while (ss >> token){
        in[i++] = token - 1;
    }
}


int main(){
    string line;
    int ncase = 0;
    while(getline(cin, line)){
        split(line);
        printf("Case %d: %d\n", ++ncase, backtracking(0));
    }
    return 0;
}