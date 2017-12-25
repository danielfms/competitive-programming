#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k, m;
    double v_c;
    char c;
    string line;
    getline(cin, line);
    stringstream ss;
    ss << line;
    ss>>n;
    while(n--){
        map<char, double> ma;
        getline(cin, line);
        ss.clear();
        ss << line;
        ss >> k;
        //cout << k << endl;
        for(int i = 0; i < k; i++){
            getline(cin, line);
            ss.clear();
            ss << line;
            ss >> c;
            ss >> v_c;
            ma[c] = v_c;
        }
        getline(cin, line);
        ss.clear();
        ss << line;
        ss >> m;
        string::iterator s;
        double money = 0.0;
        for(int i = 0; i < m ; i++){
            getline(cin, line);
            for(s = line.begin() ; s < line.end(); s++){
                money += ma.count(*s) > 0 ? ma[*s] : 0.0;
            }
        }
        printf("%.2f$\n", (money/100.0));
    }

    return 0;
}