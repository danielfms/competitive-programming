//uva: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4516
#include <bits/stdc++.h>

using namespace std;


int main(){
    int w,h;
    //Pick's Theorem. Area = i + b/2 - 1
    // i: points, b: lines
    while(cin>>h && cin>>w){
        int points=0,lines=0;
        for(int i=0;i<h;i++){
            bool flag=false; //Si un punto esta dentro del poligono.
            for(int j=0;j<w;j++){
                char c;
                cin>>c;
                if(c=='\\' || c=='/'){        
                    lines+=1;
                    flag=!flag;
                }
                if(c=='.'&& flag)
                    points+=1;
            }
        }  
        cout<<(points+lines/2)<<endl;
    }
    
    return 0;
}

//ayuda: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=9