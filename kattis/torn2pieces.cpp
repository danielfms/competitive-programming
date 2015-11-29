#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void BFS(map< string,vector<string> > &G, string nodo, string destino,map<string, bool> &visitados){
	queue<string> Q;
	Q.push(nodo);
	visitados[nodo]=true;
	map<string,string> padres;
	padres[nodo] = "#";
	vector<string> respuesta;
	while(!Q.empty()){
		string e = Q.front();
		Q.pop();
		if(e.compare(destino)==0){
			string index = e;
			while(padres[index].compare("#")!=0){
				respuesta.push_back(index);
				index = padres[index];
			}
			respuesta.push_back(index); //Nodo inical
			int lr=respuesta.size()-1;
			for(int k=lr;k>0;k--)
				cout<<respuesta[k]<<" ";
			cout <<respuesta[0]<<endl;
			return;
		}
		int le=G[e].size();
		for(int i=0;i<le;i++){
			string v= G[e][i];
			if(!visitados[v]) {
				visitados[v]=true;
				Q.push(v);
				padres[v] = e;
			}
		}
	}
	cout<<"no route found"<<endl;
	return;
}

int nextInt(){
    string buffer;
    getline(cin,buffer);
    return atoi(buffer.c_str());
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N = nextInt();
	//cin>>N;
	//getchar();
	map< string,vector<string> > G;
	map<string, bool> visitados;
	string line,inicio,destino,node,vecino;

	for(int i=0;i<N;i++){
		getline(cin,line);
		stringstream ss(line);
		ss >> node;
		while(ss >> vecino){
			G[node].push_back(vecino);
			G[vecino].push_back(node);
			visitados[node]=false;
			visitados[vecino]=false;
		}
	}
	getline(cin,line);
	stringstream cs(line);
	cs >> inicio;
	cs >> destino;
	BFS(G,inicio,destino,visitados);

	return 0;
}
//https://open.kattis.com/problems/torn2pieces
