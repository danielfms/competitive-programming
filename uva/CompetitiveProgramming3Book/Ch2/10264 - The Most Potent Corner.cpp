#include <bits/stdc++.h>
using namespace std;
int corners[32768];
int sums[32768];

int main(){
    int n, k, ans, neighbor;
    while(scanf("%d", &n) != EOF){
        k = 1 << n;
        ans = -1;
        memset(sums, 0, sizeof sums);
        memset(corners, 0, sizeof corners);
        for(int i = 0; i < k; i++){
            scanf("%d", &corners[i]);
        }

        for(int i = 0; i < k; i++){
            for(int j = 0; j < n; j++){
                //Generar los vecinos del numero i, 
                //intercambiando el valor del bit j de i
                neighbor = i ^ (1 << j);
                sums[i] += corners[neighbor];
            }
        }
        for(int i = 0; i < k; i++){
            for(int j = 0; j < n; j++){
                neighbor = i ^ (1 << j);
                ans = max(ans, sums[i] + sums[neighbor]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}