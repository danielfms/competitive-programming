#include <bits/stdc++.h>
using namespace std;
int N,W,L;

bool split(queue<int> &wagons, int n,int maxW){
  int contL = 0;
  if(wagons.front() != 1) contL += 1;

  while(!wagons.empty()){
    int newi = wagons.front() + n; // saco el primer indice
    
    cout<<"newi: "<<newi<<" contL: "<<contL<<" |";
    wagons.pop(); // elimino ese primer numero
    // si el proximo vagons esta mas adelante y la distancia es menor o igual al numero aumento una loco300lom
    if( newi < wagons.front()) contL += 1;
    else if(newi >= maxW){ // si ya termine
      if(newi <= N) contL += 1;
      break;
    }else if(newi > wagons.front()){
      contL += 1;
      wagons.pop();
      while(newi < wagons.front()) wagons.pop();
    }
    if(contL > L) return false;
  }
  cout<<endl;
  cout<<"contL "<<contL<<endl;
  return true;
}



int main(){
  int t, wi, maxW;
  cin>>t;
  while(t--){
    cin>> N >> W >> L;
    queue<int> v;
    maxW = -1;
    while(W--){
      cin >> wi;
      maxW = max(maxW, wi);
      v.push(wi);
    }cout<<N<<" "<<W<<" "<<L<<endl;
    cout << split(v, 1, maxW) << endl;
  }

  return 0;
}
