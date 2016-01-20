// The Pythagorean Theorem
// https://www.urionlinejudge.com.br/judge/en/problems/view/1582
#include <bits/stdc++.h>

int gcd(int a, int b){
	int tmp;
	while(b){
		a %= b;
		tmp = a;
		a = b;
		b = tmp;
	}
	return a;
}

using namespace std;

int main (){
	double a, b, c, ma, result;

	while(cin>>a>>b>>c){
		ma = max(max(a,b),c);
		if(ma == a){
			result = hypot (b, c);
		}else if(ma == b){
			result = hypot (a, c);
		}else if(ma == c){
			result = hypot (a, b);
		}
		if(result == ma){
			if(gcd(a,gcd(b,c))==1)
				cout<<"tripla pitagorica primitiva"<<endl;
			else
				cout<<"tripla pitagorica"<<endl;
		}
		else{
			cout<<"tripla"<<endl;
		}

	}
  return 0;
}
