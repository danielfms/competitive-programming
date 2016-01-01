// 1006 - Hex-a-bonacci
// http://www.lightoj.com/volume_showproblem.php?problem=1006

#include <bits/stdc++.h>
using namespace std;

long long a, b, c, d, e, f;
map<long long,long long> dp;
long long fndp(long long n){    
    if(dp.count(n)>0)
        return dp[n];
    else{
        long long f = fndp(n-1) + fndp(n-2) + fndp(n-3) + fndp(n-4) + fndp(n-5) + fndp(n-6);
        dp[n] = f % 10000007;
        return f;
    }   
}

long long fn( long long n ) {
    if( n == 0 ) return a;
    if( n == 1 ) return b;
    if( n == 2 ) return c;
    if( n == 3 ) return d;
    if( n == 4 ) return e;
    if( n == 5 ) return f;
    
    return( fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6) );
}
int main() {
    long long n, caseno = 0, cases;
    scanf("%lld", &cases);
    while( cases-- ) {
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);
        dp[0] = a % 10000007;
        dp[1] = b % 10000007;
        dp[2] = c % 10000007;
        dp[3] = d % 10000007;
        dp[4] = e % 10000007;
        dp[5] = f % 10000007;
        printf("Case %lld: %lld\n", ++caseno, fndp(n)% 10000007);
        dp.clear();
    }
    return 0;
}