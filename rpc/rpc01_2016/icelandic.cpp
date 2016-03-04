#include <bits/stdc++.h>
using namespace std;
#define NMAX 2000002
int stations[NMAX][2];
int sums[NMAX];

int main(){
  int T,N,G,D,cont;
  cin>>T;
  while(T--){
    cin>>N;
    cont = 0;
    int ans = -1;
    for(int i=1;i<=N;i++){
      cin>>G>>D;
      stations[i][0] = G;
      stations[i][1] = D;
      stations[i+N][0] = G;
      stations[i+N][1] = D;

      sums[i] = 0;
      sums[i+N] = 0;
    }

    for(int i=1;i<=2*N;i++){
      int sum = stations[i][0] - stations[i][1];
      if (sums[i-1]>0) sum += sums[i-1];
      if(sum<0) cont = 0;
      else cont+=1;
      sums[i] = sum;
      //cout<<sum<<" ";
      if(cont == N){
        ans = i;
        break;
      }
    }
    if(ans==-1)
      cout<<"IMPOSSIBLE"<<endl;
    else
      cout<<ans-(N-1)<<endl;
  }

  return 0;
}
