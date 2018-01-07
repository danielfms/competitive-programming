#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, digits, a, b;
    bool flag;
    while(scanf("%d", &n), n){
        digits = floor(log2(n)) + 1;
        flag = true;
        a = b = 0;
        for(int i = 0; i < digits; i++){
            if(n & (1 << i)){
                if(flag){
                    a |= (1 << i);
                }else{
                    b |= (1 << i);
                }
                flag = !flag;
            }
        }
        printf("%d %d\n", a, b);
    }
    return 0;
}