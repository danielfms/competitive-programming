#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    if(n<=5 || n%2==1)
        cout<<"0"<<endl;
    else{
        cout<<((n/2-1)/2)<<endl;
    }
                    

}