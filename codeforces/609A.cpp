// AC
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,a,ans=0,cont=0;
    vector<int> v;
    scanf("%d %d",&n,&m);
    while(n--){
        scanf("%d",&a);
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    for(int i=v.size()-1;i>=0;i--){
        cont+= v[i];
        ans+=1;
        if(cont>=m)
            break;
    }
    printf("%d\n",ans);
}
