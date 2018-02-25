#include <bits/stdc++.h>
using namespace std;
int main(){
    int tc;
    float n, p;
    string line;
    stringstream ss;
    getline(cin, line);
    ss << line;
    ss >> tc;
    getline(cin, line);
    while(tc--){
        map<string, float> trees;
        n = 0;
        while(getline(cin, line)){
            if(line == ""){
                break;
            }
            if(trees.count(line) == 0){
                trees[line] = 0;
            }
            trees[line] += 1;
            n += 1;
        }
        // map<string, float>::iterator it;
        // for(it = trees.begin(); it != trees.end(); ++it){
        //     p = (it->second / n) * 100.0;
        //     cout << it->first << " " << fixed << setprecision(4) << p << endl;  
        // }
        
        for (auto &[k, v] : trees){
            p = (v / n) * 100.0;
            cout << k << " " << fixed << setprecision(4) << p << endl; 
        }
        if(tc > 0){
            cout<<endl;
        }
    }
    return 0;
}