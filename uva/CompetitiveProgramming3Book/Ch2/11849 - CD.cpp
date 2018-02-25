#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m, x, ans;
    while(scanf("%d %d", &n, &m), (n || m)){
        set<int> cds;
        ans = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            cds.insert(x);
        }
        for(int i = 0; i < m; i++){
            scanf("%d", &x);
            if(cds.count(x) != 0){
                ans += 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}