#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001
bitset<MAX> calendar;
vector<int> split(string s){
    vector<int> v;
    stringstream ss(s);
    int token;
    while (ss >> token){
        v.push_back(token);
    }
    return v;
}

int main(){
    string line;
    int n, m;
    while(getline(cin, line)){
        bool conflict = false;
        vector<int> v = split(line);
        n = v[0]; m = v[1];
        if(n == 0 && m == 0){
            return 0;
        }
        calendar.reset();
        for(int i = 0; i < n; i++){
            getline(cin, line);
            v = split(line);
            for(int j = v[0]; j < v[1]; j++){
                if(calendar[j]){
                    conflict = true;
                    break;
                }
                calendar.set(j);
            }

        }
        for(int i = 0; i < m; i++){
            getline(cin, line);
            v = split(line);
            for(int k = 0; k < MAX and !conflict; k += v[2]){
                for(int j = v[0]; j < v[1] and j + k < MAX ; j++){
                    if(calendar[j + k]){
                        conflict = true;
                        break;
                    }
                    calendar.set(j + k); 
                }
                if(conflict){
                    break;
                }
            }    
        }

        if(conflict){
            printf("CONFLICT\n");
        }else{
            printf("NO CONFLICT\n");
        }
            
    }
  return 0;
}