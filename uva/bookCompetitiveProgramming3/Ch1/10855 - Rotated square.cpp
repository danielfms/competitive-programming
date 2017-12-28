#include <bits/stdc++.h>
using namespace std;
#define MAX 3000
char A[MAX][MAX], B[MAX][MAX];
void solver(int nA, int nB){
    int c0 = 0, c90 = 0, c180 = 0, c270 = 0;
    int n = nB * nB;
    for(int i = 0; i <= nA - nB; i++){
        for(int j = 0; j <= nA - nB; j++){
            int f0 = 0, f90 = 0, f180 = 0, f270 = 0;
            for(int ii = 0, ii2 = nB -1; ii < nB; ii++, ii2--){
                for(int jj = 0, jj2 = nB -1; jj < nB; jj++, jj2--){
                    int index_i = ii + i;
                    int index_j = jj + j;

                    //0
                    if(A[index_i][index_j] == B[ii][jj]){
                        f0 += 1;
                    }
                    //90
                    if(A[index_i][index_j] == B[jj2][ii]){
                        f90 += 1;
                    }
                    //180
                    if(A[index_i][index_j] == B[ii2][jj2]){
                        f180 += 1;
                    }
                    //270
                    if(A[index_i][index_j] == B[jj][ii2]){
                        f270 += 1;
                    }
                }
            }
            if(f0 == n){
                c0 += 1;
            }
            if(f90 == n){
                c90 += 1;
            }
            if(f180 == n){
                c180 += 1;
            }
            if(f270 == n){
                c270 += 1;
            }
        }
    }
    printf("%d %d %d %d\n", c0, c90, c180, c270);
}
int main(){
    int nA, nB;
    while(scanf("%d %d", &nA, &nB), (nA || nB)){
        for(int i = 0; i < nA; i++){
            scanf("%s", A[i]);
        }
        for(int i = 0; i < nB; i++){
            scanf("%s", B[i]);
        }
        
        solver(nA, nB);
    }
    return 0;
}