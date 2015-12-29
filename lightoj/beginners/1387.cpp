// 1387 - Setu 
// http://www.lightoj.com/volume_showproblem.php?problem=1387
#include <bits/stdc++.h>

using namespace std;

int nextInt(){
	string buffer;
	getline(cin,buffer);
	return atoi(buffer.c_str());
}

int main (){
	
	int T,N,donations;
	string line,operation,d;
	T = nextInt();
	for(int i=1;i<=T;i++){
		N = nextInt();
		donations = 0;
		cout<<"Case "<<i<<":"<<endl;
		for(int j=0;j<N;j++){
			getline(cin,line);
			stringstream ss(line);
			ss>>operation;
			if(operation == "donate"){
				ss>>d;
				donations+= atoi(d.c_str());
			}else {
				cout<<donations<<endl;
			}
		}
	}

	return 0;
}
