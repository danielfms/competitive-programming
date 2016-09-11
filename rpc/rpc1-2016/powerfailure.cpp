#include <bits/stdc++.h>
using namespace std;
int power[10000];
int p[10000];

void make_set(int x){
	p[x] = x;
}

int find_set(int x){
	if(x == p[x]) return x;
	return find_set(p[x]);
}

void union_set(int x, int y){
	int px = find_set(x);
	int py = find_set(y);
	if(px == py) return;
	if(power[px] || power[py]){
		power[px]=1;
		power[py]=1;
	}
	p[px] = py;
}

int main(){
	int t,n,m,p,c,x,y;
	char d;
	cin>>t;
	while(t--){
		cin>>n>>m>>p>>c; // n :columnas desplazamiento en x. m: filas desplazamiento en y
		memset(power,0,sizeof(power));	
			
		for(int i=0;i<n*m;i++){
			make_set(i);
		}
		
		for(int i=0;i<p;i++){
			cin>>x>>y;
			int nodo = y*n + x;
			power[nodo] = 1;
		}
		for(int i=0;i<c;i++){
			cin>>x>>y>>d;
			int nodo = y*n + x;
			if(d == 'R' && x< n-1){
				union_set(nodo, nodo +1);
			}
			if(d == 'U' && y< m-1){
				union_set(nodo, nodo + n);
			}
		}
		int cont=0;
		for(int i=0;i<n*m;i++){
			if(find_set(i) == i && !power[i])
				cont+=1;
		}
		cout<<cont<<endl;
		
	}
	
	return 0;
}
