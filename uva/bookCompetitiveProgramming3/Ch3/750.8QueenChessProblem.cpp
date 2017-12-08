#include <bits/stdc++.h>
using namespace std;
int n, a, b, s = 0;
int rows[8];

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
void backtracking(int c){
    //Si se encontro una solucion
    //e incluye la posicion de la entrada
    //la imprimo
    if(c == 8 && rows[b] == a){
        s += 1;
        printf("%2d      %d", s, rows[0] + 1);
        for(int i = 1; i < 8; i++){
            printf(" %d", rows[i] + 1);
        }
        printf("\n");
    }
    for(int r = 0; r < 8; r++){
        if(valido(r, c)){
            rows[c] = r;
            backtracking(c + 1);
        }
    }
}


int main(){
    cin>>n;
    while(n--){
        cin>>a>>b;
        a--; b--;
        s = 0;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        backtracking(0);
        if(n){
            printf("\n");
        }
    }
    return 0;
}