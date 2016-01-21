#include <bits/stdc++.h>
using namespace std;

int r[101][5];
map<char,int> m;


void toRoman(){
  string unidad[]={"", "i", "ii", "iii", "iv", "v", "vi", "vii", "viii", "ix"};
  string decena[]={"", "x", "xx", "xxx", "xl", "l", "lx", "lxx", "lxxx", "xc"};
  string roman = "";
  m['i'] = 0;
  m['v'] = 0;
  m['x'] = 0;
  m['l'] = 0;
  m['c'] = 0;

  int u,d;
  int len;
  for(int n=1;n<=100;n++){
    int u=n%10;
    int d=(n/10)%10;
    if(n==100){
        roman = "c";
    }else{
        if(n>=10){
            roman = decena[d]+unidad[u];
        }else{
            roman = unidad[n];
        }
    }
    len = roman.size();
    for(int i= 0;i<len;i++){
      m[roman[i]]= m[roman[i]] + 1;
    }
    r[n][0]= m['i'];
    r[n][1]= m['v'];
    r[n][2]= m['x'];
    r[n][3]= m['l'];
    r[n][4]= m['c'];
    //cout<<roman<<endl;
  }
}

int main(){
    toRoman();
    int n;
    while(true){
      scanf("%d",&n);
      if(n==0)return 0;
      printf("%d: %d i, %d v, %d x, %d l, %d c\n",n,r[n][0],r[n][1],r[n][2],r[n][3],r[n][4]);
    }
    return 0;
}
