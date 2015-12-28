#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, ans, aux, minV, indexMin;
    cin>>n;
    vector<long long> v(n);
    for(long long i = 0; i<n ; i++){
        cin>>v[i];            
    }
    minV = *min_element(v.begin(),v.end());
    
    for(long long i = 0; i<n ; i++){
        if(v[i]==minV){
            indexMin=i;
            break;
        }       
    }
    aux = numeric_limits<long long>::min();
    for(long long i = indexMin+1; i<2*n ; i++){
        if(v[i%n]==minV){
            aux = max(aux,i-indexMin-1);
            indexMin = i;
        }           
    }
    
    ans = n*minV + aux;
    cout<<ans<<endl;  
    return 0;
}