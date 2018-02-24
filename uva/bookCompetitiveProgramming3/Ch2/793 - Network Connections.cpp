#include <bits/stdc++.h>
using namespace std;
vector<int> split(string line){
    vector<int> v;
    stringstream ss(line);
    int token;
    string op;
    ss >> op;
    v.push_back(op == "c" ? 1 : 0);
    while(ss >> token){
        v.push_back(token);
    }
    return v;
}
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

int main(){
    int tc, n, op, a , b;
    int ans[2];
    vector<int> v;
    string line;
    stringstream ss;
    getline(cin, line);
    ss << line;
    ss >> tc;
    getline(cin, line);
    while(tc--){
        memset(ans, 0, sizeof ans);
        getline(cin, line);
        ss.clear();
        ss << line;
        ss >> n;
        UnionFind uf(n);
        while(true){
            getline(cin, line);
            if(line.empty()){
                break;
            }
            v = split(line);
            if(v[0] == 1){
                uf.unionSet(v[1] -1 , v[2] - 1);
            }else{
                ans[uf.isSameSet(v[1] -1 , v[2] - 1)] += 1;
            }
        }
        printf("%d,%d\n", ans[1], ans[0]);
        if(tc != 0){
            printf("\n");
        }
    }
    return 0;
}