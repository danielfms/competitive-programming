#include <bits/stdc++.h>
using namespace std;
int main(){
    char s[50], scpy[50];
    char end[] = "#";
    while(true){
        scanf("%s", s);
        int len = strlen(s);
        if(strcmp(s, end) == 0){
            break;
        }
        strcpy (scpy, s);
        next_permutation(s, s+len);
        if(strcmp(s, scpy) <= 0){
            printf("No Successor\n");
        }else{
            printf("%s\n", s);
        }
    }
    
    return 0;
}