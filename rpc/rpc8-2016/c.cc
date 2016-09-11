#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAX 1010
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
char M[MAX][MAX];
bool vis[MAX][MAX];
int PSC[MAX][MAX]; //Prefix Sum Columnas
int PSR[MAX][MAX]; //Prefix Sum Filas
int L,W; // w -> x , l -> y

bool isValid(int x, int y){
  return (x >= 0 && x < W && y >= 0 && y < L);
}

void moveGodzilla(pair<int, int> &p){
  int nx = p.first,ny = p.second;
  bool moveResidential = false;
  for(int i=0; i<4; i++){
    nx += dx[i];
    ny += dy[i];
    if(isValid(nx,ny) &&  !vis[nx][ny] && M[nx][ny] == 'R'){
      p = make_pair(nx,ny);
      vis[nx][ny] = 1;
      M[nx][ny] = 'U'; //ruined sector
      moveResidential = true;
      break;
    }
  }
  nx = p.first, ny = p.second;
  if(!moveResidential){
    for(int i=0; i<4; i++){
      nx += dx[i];
      ny += dy[i];
      if(isValid(nx,ny) &&  !vis[nx][ny]){
        p = make_pair(nx,ny);
        vis[nx][ny] = 1;
        break;
      }
    }
  }
}

void moveMecha(pair<int, int> &p){
  
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t, cont;
  char c;
  cin>>t;
  while(t--){
    cin>>L>>W; // w -> x , l -> y
    vector< pair<int,int> > mechas;
    pair<int, int> G; // posicion inicial del Godzila
    for(int i=0; i< W; i++){
      cont = 0;
      for(int j=0; j<L; j++){
        cin>>c;
        M[i][j] = c;

        if(c == 'M'){
          //Verificar si es mechas
          mechas.push_back(make_pair(i,j));
        }else if(c == 'G'){
          //tomar posicion de Godzila
          G = make_pair(i,j);
        }else if(c == 'R'){
          cont += 1;
        }

        //construir los dos array para prefix sum
        PSR[i][j] = cont;
      }
    }

    // Construir Prefix Sum de Columnas
    for(int i=0; i< W; i++){
      cont = 0;
      for(int j=0; j<L; j++){
        c = M[j][i];
        if(c == 'R'){
          cont += 1;
        }
        //construir los dos array para prefix sum
        PSC[j][i] = cont;
      }
    }

    cout<<solver(mechas, G)<<endl;
  }


  return 0;
}
