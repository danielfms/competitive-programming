#include <bits/stdc++.h>
using namespace std;
char ga[100][100];
int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t, a;
  cin >> t;
  while(t--){
    int cont = 0;
    cin >> a;
    for (int i=0; i<a; i++){
      cin >> ga[i];
    }
    for(int z=0;z<a;z++){
    for (int i=0; i<a; i++){
      vector< pair<int, int> > v(8);
      for(int j=0; j<a; j++){
          if(ga[i][j] == 'w'|| ga[i][j] == 'W'){
            v[0].first = i-1; v[0].second = j-1;
            v[1].first = i; v[1].second = j-1;
            v[2].first = i+1; v[2].second = j-1;
            v[3].first = i-1; v[3].second = j;
            v[4].first = i+1; v[4].second = j;
            v[5].first = i-1; v[5].second = j+1;
            v[6].first = i; v[6].second = j+1;
            v[7].first = i+1; v[7].second = j+1;

            for(int k=0;k<8;k++){
              if(v[k].first>=0 && v[k].second<a && v[k].second>=0 && v[k].first<a ){
                if(ga[v[k].first][v[k].second] == '-'){
                  cont+=1;
                  ga[v[k].first][v[k].second] = 'w';
                }

              }
            }
          }
      }
    }
  }
    cout<<cont<<endl;
  }
return 0;
}
