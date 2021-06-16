#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v;
    int n;
    while(scanf("%d", &n) != EOF){
        v.push_back(n);
        sort(v.begin(), v.end());
        int len = v.size();
        int middle = len / 2;
        if(len % 2 == 1){
            printf("%d\n", v[middle]);
        }else{
            printf("%d\n", (v[middle] + v[middle -1]) / 2);
        }
    }
    
    return 0;
}
