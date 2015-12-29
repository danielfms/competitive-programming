// 1045 - Digits of Factorial
// http://www.lightoj.com/volume_showproblem.php?problem=1045 
// Calcular el factorial: http://frodriguezdiaz.blogspot.com.co/2013/03/cuantas-cifras-tiene-un-numero-por.html
// Cambio de base: http://www.allmathwords.org/es/c/changeofbaseformula.html

#include <bits/stdc++.h>
using namespace std;


int main(){
    int T,n,c=1,ans;
    double sum[1000001], base, prev;
    sum[0] = 0.0;
    
    //Calculando el logaritmo del factorial
    //El logaritmo de una multiplicacion es igual a una suma
    for(int i=1;i<1000001;i++){
        sum[i] = sum[i-1] + log10(double(i));
    }
    
    cin>>T;
    while(T--){
        cin>>n>>base;
        //Cambio de base, y calculo de digitos
        ans = sum[n]/log10(base)+1;
        cout<<"Case "<<c++<<": "<<ans<<endl;
    }
    return 0;
}