#include <bits/stdc++.h>
using namespace std;
#define N 2001
int weights[N];//pesos de cada item
int n;


/*
*  i : item
*  j : weight current, j = w_max - w[item]
*  recorremos los items de derecha a izquierda en el arreglo
*/
int mochila(int i, int j){
  if(i <= 0 || j <= 0) return 0;
  if(weights[i-1] > j) return mochila(i-1,j);

  int max_ = -1;
  for(int k=1;k<=n;k++){
    if(weights[k-1] <= j)
      max_ = max(max_, weights[k-1]+ mochila(i-1,j-weights[k-1]));
  }
  return max(mochila(i-1,j),max_);
}

int main(void){
  int T;//casos
  cin >> T;
  while(T--){
    cin >> n;
    int max_w;//peso que soporta la mochila
    cin >> max_w;
    for(int i = 0; i < n; i++)
      cin >> weights[i];//agrega peso del elemento i
    sort(weights, weights + n);
    cout << mochila(n,max_w) << endl;
  }
  return 0;
}
