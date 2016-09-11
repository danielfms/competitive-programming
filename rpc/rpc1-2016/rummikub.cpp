#include <bits/stdc++.h>
using namespace std;
int rumi[101][4];
int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t,m;
  unordered_map<char,int> mapa;
  mapa['b']=0;
  mapa['g']=1;
  mapa['r']=2;
  mapa['y']=3;
  cin>>t;
  while(t--){
    memset(rumi,0,sizeof(rumi));
    cin>>m;
    string tile;
    bool end= false;
    for(int i=0;i<m;i++){
      cin>>tile;
      char c = tile[tile.size()-1];
      int  v = atoi(tile.substr(0,tile.size()-1).c_str());
      rumi[v][mapa[c]] = 1;
    }
    for(int i=1;i<=100;i++){
      int cont=0;
      bool flag = false;
      for(int j=0;j<4;j++){
        cont+= rumi[i][j];
        if(rumi[i][j] && rumi[i+1][j] && rumi[i+2][j])
          flag = true;
      }
      if(cont>=3 || flag){
        cout<<"YES"<<endl;
        end = true;
        break;
      }
    }
    if(!end)
      cout<<"NO"<<endl;
  }
  return 0;
}
