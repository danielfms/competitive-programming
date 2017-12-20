#include <bits/stdc++.h>
using namespace std;
int rows[8];
int b[10][10];  //b
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
int backtracking(int c, int score){
    //Se encontro una solucion retorno el valor
    if(c >= 8){
        return score;
    }
    int oo = -10000000;;
    for(int r = 0; r < 8; r++){
        if(valido(r, c)){
            rows[c] = r;
            oo = max(oo, backtracking(c + 1, score + b[r][c]));
        }
    }
    return oo;
}

int main(){
    string line;
    int k;
    cin>>k;
    while(k--){
        for(int i=0; i < 8; i++){
            scanf("%d %d %d %d %d %d %d %d", &b[i][0], &b[i][1], &b[i][2], &b[i][3], &b[i][4], &b[i][5], &b[i][6], &b[i][7]);
        }
        printf("%5d\n", backtracking(0, 0));
    }
    return 0;
}