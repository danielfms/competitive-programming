#include <bits/stdc++.h>
using namespace std;

struct pacman{
	int x,y;
	pacman(int a, int b): x(a), y(b){}
	pacman(){}
	bool operator<(const pacman& p) const{
		if (x == p.x)
			return y < p.y;
		return x < p.x;
	}
	bool operator==(const pacman& p) const{
		return x==p.x && y == p.y;
	}
};

struct state{
	pacman p1,p2;
	char move;
	bool operator<(const state& s) const{
		if ( p1 == s.p1){
			return p2 < s.p2;
		}
		return p1 < s.p1;
	}
};


char maze[50][50];
int vis[50][50][50][50];
map< state , state > p;

int dx[4] = {0, 0, 1, -1 };
int dy[4] = {1, -1, 0, 0 };
char dm[4] = {'E','W','S','N'};



int pos_valida(int x, int N){
	if(x>=N) x%=N;
	if(x<0) x = N - 1;
	return x;
}

bool BFS(int M, int N, state inicial, state &final){
	p[inicial] = inicial;
	vis[inicial.p1.x][inicial.p1.y][inicial.p2.x][inicial.p2.y] = 1;
	queue<state> q;
	q.push(inicial);
	while(!q.empty()){
		state curr = q.front();
		q.pop();
		if(curr.p1.x == curr.p2.x && curr.p1.y == curr.p2.y){
			final = curr;
			return true;
		}

		for(int i=0;i<4;i++){
			int x1 = pos_valida(curr.p1.x + dx[i],M);
			int y1 = pos_valida(curr.p1.y + dy[i],N);
			int x2 = pos_valida(curr.p2.x + dx[i],M);
			int y2 = pos_valida(curr.p2.y + dy[i],N);
			state newstate = curr;
			if(!vis[x1][y1][x2][y2] && !(maze[x1][y1] == 'G' || maze[x2][y2] == 'G' )){
					if(maze[x1][y1] == '.' || maze[x1][y1] == 'P' ){
						newstate.p1.x = x1;
						newstate.p1.y = y1;
					}
					if(maze[x2][y2] == '.' || maze[x2][y2] == 'P'){
						newstate.p2.x = x2;
						newstate.p2.y = y2;
					}
					if(!vis[newstate.p1.x][newstate.p1.y][newstate.p2.x][newstate.p2.y]){
						vis[newstate.p1.x][newstate.p1.y][newstate.p2.x][newstate.p2.y] = 1;
						newstate.move = dm[i];
						p[newstate] = curr;
						q.push(newstate);
					}
			}
		}
	}

	return false;
}

void buscarpacmans(int M, int N, state &inicial){
	inicial.move = '-';
	bool uno = false;
	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++){
			if(maze[i][j] == 'P' && !uno){
				inicial.p1.x = i;
				inicial.p1.y = j;
				uno = true;
			}else if(maze[i][j] == 'P' && uno){
				inicial.p2.x = i;
				inicial.p2.y = j;
				return;
			}
		}
}

void imprimirCamino(state final){
	int d = 0;
	stack<char> st;
	while(final.move!='-'){
		st.push(final.move);
		final = p[final];
		d+=1;
	}
	cout<<d<<" ";
	while(!st.empty()){
		cout<<st.top();
		st.pop();
	}
	cout<<endl;
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T,M,N;
	cin>>T;
	while(T--){
		cin>>M>>N;
		memset(vis,0,sizeof(vis));
		for(int i=0;i<M;i++)
			cin>>maze[i];
		state inicial, final;
		buscarpacmans(M,N,inicial);
		//cout<<"Pacman 1:"<<inicial.p1.x<<" "<<inicial.p1.y<<endl;
		//cout<<"Pacman 2:"<<inicial.p2.x<<" "<<inicial.p2.y<<endl;
		if(!BFS(M,N,inicial,final))
			cout<<"IMPOSSIBLE"<<endl;
		else
			imprimirCamino(final);
	}
	return 0;
}
