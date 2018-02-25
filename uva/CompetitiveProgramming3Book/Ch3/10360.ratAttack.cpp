#include <bits/stdc++.h>
using namespace std;
#define MAX 1025
int killed[MAX][MAX];

void setRatPopulation(int x, int y, int r, int d){
    //Recorrer todo el cuadrado con centro en (x,y)
    int xStart = max(0, x - d);
    int xEnd = min(1024, x + d);
    int yStart = max(0, y - d);
    int yEnd = min(1024, y + d);
    for(int i = xStart; i <= xEnd; i++){
        for(int j = yStart; j <= yEnd; j++){
            killed[i][j] += r;
        }
    }
}

int main(){
    int k, d, n, x, y, r;
    scanf("%d", &k);
    while(k--){
        memset(killed, 0, sizeof killed);
        scanf("%d %d", &d, &n);
        for(int i = 0; i < n; i++){
            scanf("%d %d %d", &x, &y, &r);
            setRatPopulation(x, y, r, d);
        }

        int xb = 0, yb = 0, maxr = 0;
        for(int i = 0; i < MAX; i++){
            for(int j = 0; j < MAX; j++){
                if(killed[i][j] > maxr){
                    maxr = killed[i][j];
                    xb = i;
                    yb = j;
                }else if(killed[i][j] == maxr){
                    if(i < xb){
                        xb = i;
                        yb = j;
                    }else if( i == xb && j < yb){
                        xb = i;
                        yb = j;
                    }
                }
            }
        }
        printf("%d %d %d\n", xb, yb, maxr);
    }
    return 0;
}