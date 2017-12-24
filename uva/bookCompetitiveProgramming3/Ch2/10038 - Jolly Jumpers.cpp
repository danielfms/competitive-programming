#include <bits/stdc++.h>
using namespace std;

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
    int acum = 0;
    string line;
    while(getline(cin, line)){
        vector<int> v = split(line);
        bool jolly = true;
        int size = v[0];
        if(size == 0){
            jolly = false;
        }else{
            bool flag[size - 1];
            memset(flag, false, sizeof(flag));
            for(int i = 1; i < size; i++){
                int index = abs(v[i] - v[i + 1]);
                if(index <= 0 || index >= size){
                    jolly = false;
                    break;
                }else{
                    flag[index - 1] = true;
                }
            }

            if(jolly){
                acum = accumulate(flag, flag + size - 1, 0);
                jolly = acum == size -1 ? true : false;
            }
        }
        
        if(jolly){
            printf("Jolly\n");
        }else{
            printf("Not jolly\n");
        }
    }
  return 0;
}