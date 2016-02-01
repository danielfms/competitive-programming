// Floyd-Warshall Algorithm  All Pair Shortest Path
// Explanation: https://www.youtube.com/watch?v=LwJdNfdLF9s
#include <bits/stdc++.h>
using namespace std;
#define INF numeric_limits<int>::max()
#define nodes 4
int distances[nodes][nodes];
int path[nodes][nodes];

void init(){
  for(int i=0; i<nodes;i++)
    for(int j=0;j<nodes;j++){
      if(i == j) distances[i][j] = 0;
      else distances[i][j] = INF;
      path[i][j] = -1;
    }
}
void floydwarshall(){
  for(int k=0;k<nodes;k++)
    for(int i=0;i<nodes;i++)
      for(int j=0;j<nodes;j++){
        if(distances[i][k] == INF || distances[k][j] == INF)
          continue;
        if(distances[i][j] > distances[i][k] + distances[k][j]){
          distances[i][j] = distances[i][k] + distances[k][j];
          path[i][j] = path[k][j];
        }
      }
}
void printmatrix(){
    cout<<"Matrix distances"<<endl;
    for(int i=0;i<nodes;i++){
      for(int j=0;j<nodes;j++){
          cout<<distances[i][j]<<" ";
      }
      cout<<endl;
    }

    cout<<"Matrix path"<<endl;
    for(int i=0;i<nodes;i++){
      for(int j=0;j<nodes;j++){
          cout<<path[i][j]<<" ";
      }
      cout<<endl;
    }
}
void printpath(int from, int to){
  int prev;
  stack<int> st;
  st.push(to);
  while(true){
    prev = path[from][st.top()];
    if(prev == -1){
      cout<<"No path"<<endl;
      return;
    }
    st.push(prev);
    if(prev == from) break;
  }

  while(!st.empty()){
    cout<<st.top()<<" ";
    st.pop();
  }
  cout<<endl;
}
bool negativeCycle(){
  for(int i=0;i<nodes;i++)
    if(distances[i][i] < 0)
      return true;
  return false;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int edges,a,b,c,q,q1,q2; //nodes = 4;
  cin>>edges;
  init();
  for (int i = 0; i < edges; i++) {
    cin>>a>>b>>c;
    distances[a][b] = c;
    path[a][b] = a;
  }
  floydwarshall();
  printmatrix();
  // queries
  cin>>q;
  while(q--){
    cin>>q1>>q2;
    cout<<"Minimum distances from "<<q1<<" to "<<q2<<" is: "<<distances[q1][q2]<<endl;
    printpath(q1,q2);
  }
  return 0;
}
