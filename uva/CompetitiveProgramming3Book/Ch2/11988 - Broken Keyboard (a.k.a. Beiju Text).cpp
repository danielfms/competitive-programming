#include <bits/stdc++.h>
using namespace std;
int main(){
    string line;
    while(getline(cin, line)){
        list<char> l;
        list<char>::iterator it = l.begin();
        int len = line.size();
        for(int i = 0; i < len; i++){
            if(line[i] == '['){
                it = l.begin();
            }else if(line[i] == ']'){
                it = l.end();
            }else{
                l.insert(it, line[i]);
            }
        }
        for(auto &i : l){
            printf("%c", i);
        }
        printf("\n");
    }
    return 0;
}