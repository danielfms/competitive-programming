#include <bits/stdc++.h>
using namespace std;
int get_id(char c, map<char, int> &ids){
    int len = ids.size();
    if(ids.count(c) == 0){
        ids[c] = len;
    }
    return ids[c];
}

class UnionFind{
    private: 
        vector<int> p, rank, s;
    public:
        UnionFind(int N){
            rank.assign(N, 0);
            p.assign(N,0);
            s.assign(N, 0);
            for(int i = 0; i < N; i++){
                p[i] = i;
                s[i] = 1;
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
                s[x] += s[y];
            }else{
                p[x] = y;
                s[y] += s[x];
                if(rank[x] == rank[y]){
                    rank[y]++;
                }
            }
        }
        int getSize(int i){
            int x = findSet(i);
            return s[x];
        }
};

int main(){
    int tc, a, b;
    string token;
    cin >> tc;
    string s;
    while(tc--){
        vector<pair<int, int> > v;
        map<char, int> ids;
        while(true){
            cin >> s;
            if(s[0] == '*') break;
            a = get_id(s[1], ids);
            b = get_id(s[3], ids);
            v.push_back(make_pair(a, b));
        }
        cin >> s;
        istringstream iss(s);
        while(getline(iss, token, ',')){
            get_id(token.c_str()[0], ids);
        };
        //create unionFind
        int n = ids.size(), lv = v.size();
        UnionFind uf(n);
        for(int i = 0; i < lv; i++){
            uf.unionSet(v[i].first, v[i].second);
        }
        set<int> tmp;
        int trees = 0, acorns = 0, x;
        for(int i = 0; i < n; i++){
            x = uf.findSet(i);
            if(tmp.count(x) == 0){
                if(uf.getSize(i) > 1){
                    trees += 1;
                }else{
                    acorns += 1;
                }
                tmp.insert(x);
            }
        }
        cout << "There are " << trees << " tree(s) and " << acorns << " acorn(s)."<<endl;
    }
    return 0;
}