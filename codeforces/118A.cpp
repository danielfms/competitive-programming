//AC
#include <bits/stdc++.h>
using namespace std;

bool isConsonant(char c){
  if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='y' ) return false;
  return true;
}

int main(){
  //simplificar usando strchr("aeiouy",s);
  string cad,ans="";
  cin>>cad;
  for(int i=0;i<cad.size();i++){
    if(isConsonant(tolower(cad[i])))
      ans+=tolower(cad[i]);
  }

  for(int i=0;i<ans.size();i++){
    cout<<"."<<ans[i];
  }


  return 0;
}
