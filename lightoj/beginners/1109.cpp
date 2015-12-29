// 1109 - False Ordering
// http://www.lightoj.com/volume_showproblem.php?problem=1109
#include <bits/stdc++.h>

using namespace std;

int divs[1001];
int nums[1001];

void comp(int n){
	for(int i=1;i<=n;i++){
			if(n%i == 0){
				divs[n]+=1;
			}
	}
}

void div(){
	for(int i=1;i<1001;i++){
			comp(i);
	}
}

void ordering(){
	int xd,x,yd,y;
	for(int i=1;i<1001;i++){
		for(int j=1;j<1000;j++){
				x = nums[j+1];
				xd = divs[x];
				y = nums[j];
				yd = divs[y];
				if(xd < yd || (xd == yd && x > y)){
					nums[j] = x;
					nums[j+1] = y;
				}
		}
	}
}

void fill_num(){
	for(int i=1;i<1001;i++)
		nums[i]=i;
}


int main (){
	fill_num();
	div();
	ordering();

	int T,n;
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n;
		cout<<"Case "<<i<<": "<<nums[n]<<endl;;
	}

	return 0;
}
