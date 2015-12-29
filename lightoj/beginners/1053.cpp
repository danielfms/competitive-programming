// 1053 - Higher Math 
// http://www.lightoj.com/volume_showproblem.php?problem=1053
#include <bits/stdc++.h>

using namespace std;

int main (){
	int N;
	double a, b, c, ma, result;
	cin>>N;
	
	for(int i=1;i<=N;i++){
		cin>>a>>b>>c;
		ma = max(max(a,b),c);
		if(ma == a){
			result = hypot (b, c);
		}else if(ma == b){
			result = hypot (a, c);
		}else if(ma == c){
			result = hypot (a, b);
		}
		
		cout<<"Case "<<i<<": ";
		if(result == ma)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
  return 0;
}
