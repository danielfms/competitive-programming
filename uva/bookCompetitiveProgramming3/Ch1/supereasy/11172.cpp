/* 11172 - Relational Operator 
 https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2113
 */

#include <stdio.h>

int main(){
    
    int T;
    long long A,B;
    scanf("%d",&T);
    while(T--){
        scanf("%ld %ld",&A,&B);
        if(A==B)
            printf("=\n");
        else if(A<B)
            printf("<\n");
        else
            printf(">\n");
    }
    return 0;
}