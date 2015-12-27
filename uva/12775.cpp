#include <iostream>
#include <vector>

using namespace std;

int mcd(int a, int b){
    if(b==0)
        return a;
    return mcd(b, a%b);
}

int count(int s[],int m, int n){
	vector<int> table(n+1,0);
    //memset(table,0,sizeof(table));

	table[0]=1;

	for(int i=0;i<m;i++)
		for(int j=s[i];j<=n;j++)
			table[j]+=table[j-s[i]];

	return table[n];
}

int main(){
	int t,m=3,n;
	cin>>t;


	for(int i=1;i<=t;i++){
		int s[3];
		cin>>s[0]>>s[1]>>s[2]>>n;
        int uno=mcd(s[0],s[1]);
        int dos=mcd(s[2],n);
		int md= mcd(uno,dos);

		//cout<<"MCM: "<<mcd<<endl;
		s[0]=s[0]/md;
		s[1]=s[1]/md;
		s[2]= s[2]/md;
		n = n/md;

		cout<<"Case "<<i<<": "<<count(s,m,n)<<endl;
	}
	



	return 0;
}