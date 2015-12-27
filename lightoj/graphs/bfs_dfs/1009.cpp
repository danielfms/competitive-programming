#include <bits/stdc++.h>

using namespace std;

void BFS(map<int, vector <int> > &G,int nodo,map<int, bool> &visitados, bool b, int &V,int &L, map<int, bool> &raza){
    queue<int> Q;
    Q.push(nodo);
    visitados[nodo]=true;
    raza[nodo] = b;
    if(b)
        V+=1;
    else
        L+=1;
    
    while(!Q.empty()){
        int e= Q.front();
        Q.pop();
        //cout<<e<<", ";
        
        for(int i = 0 ; i < G[e].size(); i++){
            int v=G[e][i];
            if(!visitados[v]){
                visitados[v]=true;
                Q.push(v);
                
                b=!raza[e];
                raza[v]=b;
                if(b)
                    V+=1;
                else
                    L+=1;  
            }  
        }     
    }
    //cout<<endl;
}


int main(){
    
    int casos, peleas, A, B;
    
    cin>>casos;
   
    //cout<<grafo.size()<<endl;
    for(int i = 1; i <= casos; i++){
        cin>>peleas;
        map<int, vector<int> > grafo;
        for(int j = 0; j < peleas; j++){
            cin>>A>>B;   //los que están peleando
            grafo[A].push_back(B);
            grafo[B].push_back(A);
            //cout<<grafo[A-1][0]<<endl;
        }
        //cout<<grafo.size()<<endl;
            map<int,bool> visitados;
            map<int,bool> raza;
            int total=0;
            int V=0,L=0;

            for(map<int, vector <int> >::iterator it=grafo.begin(); it!=grafo.end(); ++it){
                int k= it->first;
                V=0;
                L=0;
                if(!visitados[k]){
                    BFS(grafo,k,visitados,true,V,L,raza); 
                    total+=max(V,L); //Suma de maximos en cada isla.
                    //cout<<"Hola"<<endl;
                }
                    //cout<<"L: "<<L<<" , V: "<<V<<endl;
        
                /*for(map<int,bool> ::iterator it=raza.begin(); it!=raza.end(); ++it) cout<<it->second<<" ";
                cout<<endl;*/
                
            }
            cout<<"Case "<<i<<": "<<total<<endl;
            
              
    }
    
    /*for(int j = 0; j < grafo.size(); j++){
        int l= grafo[j].size();
        cout<<"Nodo["<<j<<"]: ";
        for(int i=0;i<l;i++){
            cout<<grafo[j][i]<<" ";
        }
        cout<<endl; 
    }*/
    
    return 0;
}