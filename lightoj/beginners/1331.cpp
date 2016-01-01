// 1331 - Agent J 
// http://lightoj.com/volume_showproblem.php?problem=1331
#include <bits/stdc++.h>
using namespace std;
int main(){
    int T,caseno=1;
    double r1,r2,r3,a,b,c,s,area,angA,angB,angC,pi,razon;
    pi = 2.0*acos(0.0);
    cin>>T;
    while(T--){
        cin>>r1>>r2>>r3;
        a = r2 + r3;
        b = r1 + r3;
        c = r1 + r2;
        s = (a+b+c)/2.0;
        area = sqrt(s*(s-a)*(s-b)*(s-c));
        angC = acos((pow(b,2)+pow(a,2) - pow(c,2))/(2.0*b*a)); // radianes
        angC = (180.0*angC)/pi;  // grados
        razon = angC/360.0;
        area-= razon*(pi*pow(r3,2));
        
        angB = acos((pow(c,2)+pow(a,2) - pow(b,2))/(2.0*a*c)); // radianes
        angB = (180.0*angB)/pi;  // grados
        razon = angB/360.0;
        area-= razon*(pi*pow(r2,2));
        
        angA = acos((pow(b,2)+pow(c,2) - pow(a,2))/(2.0*b*c)); // radianes 
        angA = (180.0*angA)/pi;  // grados
        razon = angA/360.0;
        area-= razon*(pi*pow(r1,2));
        
        printf("Case %d: %lf\n",caseno++,area);
        
        
    }
    
    return 0;
}