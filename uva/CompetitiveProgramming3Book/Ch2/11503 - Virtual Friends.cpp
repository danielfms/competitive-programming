#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

int getId(string c, map<string, int> &ids){
    int len = ids.size();
    if(ids.count(c) == 0){
        ids[c] = len;
    }
    return ids[c];
}

class UnionFind{
    private: 
        vector<int> p;
        vector<int> rank;
        vector<int> s;
    public:
        UnionFind(int N){
            rank.assign(N, 0);
            p.assign(N,0);
            s.assign(N,0);
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
                
                s[x] += x != y ? s[y] : 0;
            }else{
                p[x] = y;
                s[y] += x != y ? s[x] : 0;
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc, f, a, b, n;
    string fa, fb;
    cin >> tc;
    while(tc--){
        map<string, int> ids;
        vector<pair<int, int> > friendships;
        cin >> f;
        for(int i = 0; i < f; i++){
            cin >> fa >> fb;
            a = getId(fa, ids);
            b = getId(fb, ids);
            friendships.push_back(make_pair(a, b));
        }
        n = ids.size();
        UnionFind uf(n);
        for(int i = 0; i < f; i++){
            a = friendships[i].first;
            b = friendships[i].second;
            uf.unionSet(a, b);
            cout<< uf.getSize(a) << endl;
        }
        
    }
    return 0;
}