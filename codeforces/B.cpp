#include <bits/stdc++.h>
//http://codeforces.com/contest/612
//B. HDD is Outdated Technology

using namespace std;

int main(){
    vector<pair<long long,long long> > v;
    long long n;
    string line;
    
    cin>>n;
    getchar();
    getline(cin,line);
    stringstream ss(line);
    string num;
    
    for(long long i=0;i<n;i++){
        ss>>num;
        v.push_back(make_pair(atoi(num.c_str()),i));
    }
                    
    sort(v.begin(),v.end());
    long long cont=0;
    for(long long i=0;i<n-1;i++)
        cont+= abs(v[i].second -v[i+1].second);
                    
    cout<<cont<<endl;
                    
    return 0;   
}