// 1042 - Secret Origins 
// http://lightoj.com/volume_showproblem.php?problem=1042

#include <bits/stdc++.h>
using namespace std;

void convBinary(int n,vector<int> &v){
    while(n){
        if(n & 1)
            v.push_back(1);
        else
            v.push_back(0);
        n >>= 1;
    } 
    //Permutacion: 8: 1000, add 0, 01000, permu: 16: 10000
    v.push_back(0);
    //Esta en al reves, hay que ordenarlo.
    reverse(v.begin(), v.end());
    // Otra forma es intercambiar el primer 0 y 1 con un for
}

int convDecimal(vector<int> &v){
    int ans=0;
    int len = v.size()-1;
    for(int i=0;i<v.size();i++){
        ans+= v[i]*pow(2,len-i);
    }
    return ans;
}

int main(){
    int T,n,c=1,ones;
    vector <int> v;
    scanf("%d",&T);
    while(T--){
        v.clear();
        scanf("%d",&n);
        convBinary(n,v);
        next_permutation(v.begin(),v.end());
        printf("Case %d: %d\n",c++,convDecimal(v));
    }
    return 0;
}