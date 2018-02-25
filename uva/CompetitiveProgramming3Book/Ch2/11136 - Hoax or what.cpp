#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k, d;
    long long ans;
    while(scanf("%d", &n), n){
        ans = 0;
        multiset<int> urn;
        multiset<int>::iterator first, last;
        for(int i = 0; i < n; i++){
            scanf("%d", &k);
            for(int j = 0; j < k; j++){
                scanf("%d", &d);
                urn.insert(d);
            }
            //get first and last
            first = urn.begin();
            last = urn.end(); --last;
            urn.erase(first);
            urn.erase(last);
            ans += (*last - *first);
        }
        printf("%lld\n", ans);
    }
    return 0;
}