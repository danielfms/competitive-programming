#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, b, sb, sg, l, diff, vb, vg;
    scanf("%d", &n);
    while(n--){
        multiset<int, greater <int> > green, blue, winner, tmpGreen, tmpBlue;
        multiset <int, greater <int> > :: iterator itg, itb;
        scanf("%d %d %d", &b, &sg, &sb);
        for(int i = 0; i < sg; i++){
            scanf("%d", &l);
            green.insert(l);
        }
        for(int i = 0; i < sb; i++){
            scanf("%d", &l);
            blue.insert(l);
        }
        while(true){
            tmpGreen.clear(); tmpBlue.clear();
            for(int i = 0; i < b; i++){
                if(blue.empty() or green.empty()){
                    break;
                }
                itg = green.begin(); vg = *itg;
                itb = blue.begin(); vb = *itb;
                green.erase(itg);
                blue.erase(itb);
                if(vg != vb){
                    diff = abs(vg - vb);
                    if(vb < vg){
                        tmpGreen.insert(diff);
                    }else{
                        tmpBlue.insert(diff);
                    }
                }
            }
            green.insert(tmpGreen.begin(), tmpGreen.end());
            blue.insert(tmpBlue.begin(), tmpBlue.end());
            if(blue.empty() or green.empty()){
                break;
            }
        }
        if(blue.empty() and green.empty()){
            printf("green and blue died\n");
        }else{
            if(blue.empty() and !green.empty()){
                printf("green wins\n");
                 winner = green;
            }else if(!blue.empty() and green.empty()){
                printf("blue wins\n");
                winner = blue;
            }
            for(itg = winner.begin(); itg != winner.end(); ++itg){
                printf("%d\n", *itg);
            }
        }
        if(n != 0){
            printf("\n");
        }
    }
    return 0;
}   