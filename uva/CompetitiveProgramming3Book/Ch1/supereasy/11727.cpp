// 11727 - Cost Cutting
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2827

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T,A,B,C,i=1;
    vector<int> v;
    cin>>T;
    while(T--){
        cin>>A>>B>>C;
        v.push_back(A);
        v.push_back(B);
        v.push_back(C);
        sort(v.begin(),v.end());
        cout<<"Case "<<i++<<": "<<v[1]<<endl;
        v.clear();
    }
}