/* 
 11498 - Division of Nlogonia
 https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2493
 */

#include <stdio.h>

int main(){
    int K,X,Y,a,b,i;
    
    
    while(scanf("%d",&K),K!=0){
        scanf("%d %d",&X,&Y);
        for(i=0;i<K;i++){
            scanf("%d %d",&a,&b);
            if((X-a)==0 || (Y-b)==0)
                printf("divisa\n");
            else if(a<X){
                if(b<Y)
                   printf("SO\n"); 
                else
                   printf("NO\n"); 
            }else{
                if(b<Y)
                   printf("SE\n"); 
                else
                   printf("NE\n");
            }
        }
    }
    
    return 0;
}