// 1216 - Juice in the Glass
// http://www.lightoj.com/volume_showproblem.php?problem=1216
#include <bits/stdc++.h>
using namespace std;

//V = (PI/3)*h*(r1^2 + r2^2 + r1*r2)
//Razon de cambio triangulo rectangulo

int main(){
	double r1,r2,r3,h,p,v,pi;
	int n,i=1;
	pi = 2*acos(0.0);
	scanf("%d",&n);
	
	while(n--){
		scanf("%lf %lf %lf %lf",&r1,&r2,&h,&p);
		r3 = (p/h)*(r1-r2) + r2;
		v = (pi/3.0)*p*(pow(r3,2) + pow(r2,2) + r3*r2);
	
		printf("Case %d: %f\n", i++, v);
	}
	return 0;
}
