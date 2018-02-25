#include <bits/stdc++.h>

struct Team{
    int team_number;
    int resolved;
    int penalty_time;

    bool operator<(const Team &rhs) const {
        if(resolved != rhs.resolved){
        return resolved  > rhs.resolved ; 
        }
        if(penalty_time != rhs.penalty_time){
            return penalty_time < rhs.penalty_time; 
        }
        return team_number < rhs.team_number;
    }
    bool operator==(const Team &rhs) const {
        return team_number == rhs.team_number;
    }
};

vector<int> split(string s){
    vector<int> v;
    stringstream ss(s);
    int token;
    while (ss >> token){
        v.push_back(token);
    }
    return v;
}

//digits in binary of decimal
//digits = floor(log2(n)) + 1;

//Iterate
map<string, float> trees;
map<string, float>::iterator it;
for(it = trees.begin(); it != trees.end(); ++it){
    p = (it->second / n) * 100.0;
    cout << it->first << " " << fixed << setprecision(4) << p << endl;  
}      
for (auto &[k, v] : trees){
    p = (v / n) * 100.0;
    cout << k << " " << fixed << setprecision(4) << p << endl; 
}

//speed cin, cout
ios_base::sync_with_stdio(false);
cin.tie(NULL);

//uniond find class
class UnionFind{
    private: 
        vector<int> p;
        vector<int> rank;
    public:
        UnionFind(int N){
            rank.assign(N, 0);
            p.assign(N,0);
            for(int i = 0; i < N; i++){
                p[i] = i;
            }
        }
        int findSet(int i){
            return p[i] == i ? i : (p[i] = findSet(p[i]));
        }
        bool isSameSet(int i, int j){
            return findSet(i) == findSet(j);
        }
        void unionSet(int i, int j){
            int x = findSet(i);
            int y = findSet(j);
            if(rank[x] > rank[y]){
                p[y] = x;
            }else{
                p[x] = y;
                if(rank[x] == rank[y]){
                    rank[y]++;
                }
            }
        }
};