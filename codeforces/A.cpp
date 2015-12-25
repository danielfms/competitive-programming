#include <bits/stdc++.h>
//http://codeforces.com/contest/612
//A. The Text Splitting
using namespace std;

int main(){
    int k,p,q,cont;
    string s;
    cin>>k>>p>>q;
    getchar();
    getline(cin,s);
    
    for(int i=0;i<=k;i++){
        for(int j=0;j<=k;j++){         
            if(i*p + j*q == k){
                cout<<i+j<<endl;
                cont=0;
                for(int t=0;t<i;t++,cont+=p){
                    cout<<s.substr(cont,p)<<endl;
                }
                for(int t=0;t<j;t++,cont+=q){
                    cout<<s.substr(cont,q)<<endl;
                }     
                return 0;
            }
        }
    }
    
    cout<<"-1"<<endl;
    return 0;
}