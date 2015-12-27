#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int my,lift,n,i=1,time;
	cin>>n;
	
	while(n--){
		cin>>my>>lift;
		// 19: 2*Open(3) + 2*IN/OUT(5) + 1*OUT(3)
		time = (19+ 4*(abs(my-lift) +my));
		cout<<"Case "<<i++<<": "<<time<<endl;
	}
	return 0;
}
