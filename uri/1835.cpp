// Campaign's Promise
// https://www.urionlinejudge.com.br/judge/en/problems/view/1835
#include <bits/stdc++.h>
using namespace std;

void BFS(map<int, vector <int> > &G,int nodo,map<int, bool> &visitados){
    queue<int> Q;
    Q.push(nodo);
    visitados[nodo]=true;
    while(!Q.empty()){
        int e= Q.front();
        Q.pop();
        for(int i = 0 ; i < G[e].size(); i++){
            int v=G[e][i];
            if(!visitados[v]){
                visitados[v]=true;
                Q.push(v);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int casos, peleas, A, B;
    int N,M;
    cin>>casos;
    for(int i = 1; i <= casos; i++){
        cin>>N>>M;
        map<int, vector<int> > G;
        for(int j = 0; j < M; j++){
            cin>>A>>B;
            G[A].push_back(B);
            G[B].push_back(A);
        }
        map<int,bool> visitados;
        int cont = -1;
        for(int k=1; k<=N; k++){
            if(!visitados[k]){
                  BFS(G,k,visitados);
                  cont+=1;
            }
        }
        if(cont == 0)
          cout<<"Caso #"<<i<<": a promessa foi cumprida"<<endl;
        else
          cout<<"Caso #"<<i<<": ainda falta(m) "<<cont<<" estrada(s)"<<endl;
    }
    return 0;
}
