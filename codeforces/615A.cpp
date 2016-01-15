//AC
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    int n,m,x;
    cin>>n>>m;
    getchar();
    set<string> myset;
    string line,num;
    while(n--){
      getline(cin,line);
      stringstream ss(line);
      ss>>num;
      x = atoi(num.c_str());
      while(x--){
        ss>>num;
        if(myset.count(num)==0){
          myset.insert(num);
        }
      }
    }
    if(myset.size() == m)
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
    return 0;
}
