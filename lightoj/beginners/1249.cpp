// 1249 - Chocolate Thief 
// http://www.lightoj.com/volume_showproblem.php?problem=1249
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int nextInt(){
    string num;
    getline(cin,num);
    return atoi(num.c_str());
}

int main(){
    int T,n,c=1,vol;
    string line,name,l,w,h;
    vector<pair<int, string> > v;
    T = nextInt();
    while(T--){
        n = nextInt();
        for(int i=0;i<n;i++){
            getline(cin,line);
            stringstream ss(line);
            ss>>name;
            ss>>l;
            ss>>w;
            ss>>h;
            vol = atoi(l.c_str())*atoi(w.c_str())*atoi(h.c_str());
            v.push_back(make_pair(vol,name));
        }
        sort(v.begin(),v.end());
        if(v[0].first == v[n-1].first)
            cout<<"Case "<<c++<<": "<<"no thief"<<endl;
        else{
           cout<<"Case "<<c++<<": "<<v[n-1].second<<" took chocolate from "<<v[0].second<<endl; 
        }
        v.clear();
    }   
    return 0;
}