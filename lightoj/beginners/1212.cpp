// 1212 - Double Ended Queue
// http://lightoj.com/volume_showproblem.php?problem=1212

#include <bits/stdc++.h>
using namespace std;
int main(){
    int T,c=1,n,m,cont,num;
    string operation,op1,op2,op3,op4;
    list<int> dq;
    op1 = "pushLeft";
    op2 = "pushRight";
    op3 = "popLeft";
    op4 = "popRight";
    cin>>T;
    while(T--){
        cont = 0;
        cin>>n>>m;
        dq.clear();
        cout<<"Case "<<c++<<":"<<endl;
        for(int i=0;i<m;i++){
            cin>>operation;
            if(operation == op1){
                cin>>num;
                if(cont<n){
                    dq.push_front(num);
                    cont+=1;
                   cout<<"Pushed in left: "<<num<<endl;
                }else{
                    cout<<"The queue is full"<<endl;
                }
            }else if(operation == op2){
                cin>>num;
                if(cont<n){
                    dq.push_back(num);
                    cont+=1;
                    cout<<"Pushed in right: "<<num<<endl;
                }else{
                    cout<<"The queue is full"<<endl;
                }
            }else if(operation == op3){
                if(!dq.empty()){
                    num = dq.front();
                    cout<<"Popped from left: "<<num<<endl;
                    cont-=1;
                    dq.pop_front();
                }else{
                    cout<<"The queue is empty"<<endl;
                }
            }else if(operation == op4){
                if(!dq.empty()){
                    num = dq.back();
                    cout<<"Popped from right: "<<num<<endl;
                    cont-=1;
                    dq.pop_back();
                }else{
                    cout<<"The queue is empty"<<endl;
                }
            }
        }
    }
    return 0;
}