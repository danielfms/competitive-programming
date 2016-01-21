// 10679 - I Love Strings!!
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void construirTabla(string &patron, int *tabla){
    int index =0;
    for(int i=1; i < patron.size();){
        if(patron[i] == patron[index]){
            tabla[i] = index + 1;
            index++;
            i++;
        }else{
            if(index != 0){
                index = tabla[index-1];
            }else{
                tabla[i] =0;
                i++;
            }
        }
    }
}


bool KMP(string &texto, string &patron){

    int tabla[patron.size()];
    construirTabla(patron,tabla);
    int i=0;
    int j=0;
    while(i < texto.size() && j < patron.size()){
        if(texto[i] == patron[j]){
            i++;
            j++;
        }else{
            if(j!=0){
                j = tabla[j-1];
            }else{
                i++;
            }
        }
        if(j == patron.size()){
            return true;
        }
    }

    return false;
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int k,q,t;
    string S,T;
    cin>>k;
    while(k--){
        cin>>S;
        cin>>q;
        while(q--){
            cin>>T;
            if(KMP(S,T))
                cout<<"y"<<endl;
            else
                cout<<"n"<<endl;
        }
    }
    return 0;
}
