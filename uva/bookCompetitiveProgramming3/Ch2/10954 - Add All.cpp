#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, d, ans, a, b, c;
    while(scanf("%d", &n), n){
        ans = 0;
        priority_queue<int, vector<int>, greater<int> > pq;
        for(int i = 0; i < n; i++){
            scanf("%d", &d);
            pq.push(d);
        }
        while(pq.size() >= 2){
            a = pq.top(); pq.pop();
            b = pq.top(); pq.pop();
            c = a + b;
            pq.push(c);
            ans += c;
        }
        printf("%d\n", ans); 
    }
    return 0;
}