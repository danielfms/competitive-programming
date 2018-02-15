#include <bits/stdc++.h>
using namespace std;
#define MAX 1000002
int v[MAX];
int main(){
    int tc, n;
    scanf("%d", &tc);
    while(tc--){
        map<int, int> m;
        scanf("%d", &n);
        for(int k = 0; k < n; k++){
            scanf("%d", &v[k]);
            m[v[k]] = 0;
        }
        int i = 0, j = 0;
        int ans = 0;
        bool moveJ = true;
        while(n) {
            //move j
            while(moveJ && j <= n){
                m[v[j]] += 1;
                if(m[v[j]] > 1 || j == n){
                    moveJ = false;
                    ans = max(ans, j - i);
                    break;
                }
                j += 1;
            }

            //Igualar para no perder los indices,
            //en comparacion v[i] y v[j]
            if(j >= n){
                j = n - 1;
            }

            //moveI
            while(!moveJ && i <= j){
                m[v[i]] -= 1;
                if(v[i] == v[j]){
                    moveJ = true;
                    i += 1; j += 1;
                    break;
                }
                i += 1;
            }

            if(j >= n -1){
                break;
            }
        }
        //si la respuesta es cero pero n es mayor a cero,
        //entonces suma 1
        if(ans == 0 && n > 0){
            ans += 1;
        }

        printf("%d\n", ans);
    }
    
    return 0;
}