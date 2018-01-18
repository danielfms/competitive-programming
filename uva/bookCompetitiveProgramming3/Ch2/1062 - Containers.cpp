#include <bits/stdc++.h>
using namespace std;
int main(){
    string containers;
    int c = 1; 
    while(cin >> containers){
        if(containers == "end"){
            break;
        }

        vector<stack<char> > ss;
        for(int i = 0; i < containers.size(); i++){
            bool flag = false;
            for(int k = 0; k < ss.size(); k++){
                if(ss[k].top() >= containers[i]){
                    ss[k].push(containers[i]);
                    flag = true;
                    break;
                }
            }
            if(!flag){
                stack<char> s;
                s.push(containers[i]);
                ss.push_back(s);
            }
        }
        printf("Case %d: %d\n", c++, ss.size());
    }
    return 0;
}