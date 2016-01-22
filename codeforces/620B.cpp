#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int values[10] = {6,2,5,5,4,5,6,3,7,6};

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  long long a,b,ans=0,temp;
	cin>>a>>b;
	for(int i=a;i<=b;i++){
		temp = i;
		while(temp){
			ans+= values[temp%10];
			temp/=10;
		}
	}
	cout<<ans<<endl;
  return 0;
}
