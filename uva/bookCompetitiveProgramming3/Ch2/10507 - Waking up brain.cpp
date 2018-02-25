#include <bits/stdc++.h>
using namespace std;

vector<int> G[27];

void initG(){
    for(int i = 0; i < 27; i++){
        G[i].clear();
    }
}
int toInt(string s){
    stringstream ss(s);
    int n;
    ss >> n;
    return n;
}

int getId(char c, map<char, int> &ids){
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
    int n,  m, a, b, c, awake, years;
    string line;
    stringstream ss;
    while(getline(cin, line)){
        map<char, int> ids;
        initG(); //init graph
        set<int> unions;
        set<int>::iterator it;
        n = toInt(line);
        getline(cin, line);
        m = toInt(line);

        getline(cin, line);
        //el set de los despiertos es el cero
        a = getId(line[0], ids);
        b = getId(line[1], ids);
        c = getId(line[2], ids);
        unions.insert(a);
        unions.insert(b);
        unions.insert(c);
        
        for(int i = 0; i < m; i++){
            getline(cin, line);
            a = getId(line[0], ids);
            b = getId(line[1], ids);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        //creo el objeto de clase UnionFind
        UnionFind uf(n);
        //realizo las primeras uniones antes de empezar el ciclo
        for(it = unions.begin(); it != unions.end(); ++it){
            uf.unionSet(0, *it);
        }
        unions.clear();
        awake = 3;
        years = 0;
        while(true){
            for(int i = 0; i < n; i++){
                //Si esta area no esta despierta
                if(!uf.isSameSet(i, 0)){
                    int lenG = G[i].size();
                    int awakeNeighbors = 0;
                    for(int j = 0; j < lenG; j++){
                        if(uf.isSameSet(G[i][j], 0)){
                            awakeNeighbors += 1;
                        }
                    }
                    if(awakeNeighbors >= 3){
                        //El grupo de los despiertos es el cero
                        unions.insert(i);
                    }
                }
            }
            if(unions.empty()){
                break;
            }

            //Derpertar 
            for(it = unions.begin(); it != unions.end(); ++it){
                uf.unionSet(0, *it);
                awake += 1;
            }
            unions.clear();
            years += 1;
        }
        if(awake != n){
            printf("THIS BRAIN NEVER WAKES UP\n");
        }else{
            printf("WAKE UP IN, %d, YEARS\n", years);
        } 
        getline(cin, line); 
    }
    return 0;
}