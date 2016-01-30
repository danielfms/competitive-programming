// See World
// http://www.urionlinejudge.com.br/repository/UOJ_1955_en.html
#include <bits/stdc++.h>
using namespace std;
vector<int> G[1000];
int col[1000];
int vis[1000];

bool dfs(int s, int c){
    if(col[s]!=-1)
        return c == col[s];

    col[s] = c;
    vis[s] = 1;
    for(int i=0; i< G[s].size(); i++)
        if(!dfs(G[s][i],c^1))
            return false;

    return true;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,b;
    memset(col,-1,sizeof(col));
    memset(vis,0,sizeof(vis));
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>b;
            if(b==0){
                G[i].push_back(j);
                G[j].push_back(i);
            }
        }
    }
    bool ans = true;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(!dfs(i,1)){
                ans = false;
                break;
            }
        }
    }
    if(ans) cout<<"Bazinga!"<<endl;
    else cout<<"Fail!"<<endl;


    return 0;
}
