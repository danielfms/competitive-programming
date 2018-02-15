#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, op, x;
    bool isQ, isS, isPQ, onePush;
    while(scanf("%d", &n) != EOF){
        queue<int> q;
        stack<int> s;
        priority_queue<int> pq;
        isQ =  true;
        isS = true;
        isPQ = true;
        for(int i = 0; i < n; i++){
            scanf("%d %d", &op, &x);
            if(op == 1){
                q.push(x);
                s.push(x);
                pq.push(x);
            }else{
                //pq top()
                if(pq.empty()){
                    isPQ = false;
                }else{
                    isPQ = !isPQ ? false : pq.top() == x;
                    pq.pop();
                }
                //q front()
                if(q.empty()){
                    isQ = false;
                }else{
                    isQ =  !isQ ? false : q.front() == x;
                    q.pop();
                }
                //s top()
                if(s.empty()){
                    isS = false;
                }else{
                    isS = !isS ? false : s.top() == x;
                    s.pop();
                }
            }
        }
        if(isQ and !isPQ and !isS){
            printf("queue\n");
        }else if(!isQ and isPQ and !isS){
            printf("priority queue\n");
        }else if(!isQ and !isPQ and isS){
            printf("stack\n");
        }else if( isQ + isPQ + isS >= 2){
            printf("not sure\n");
        }else {
            printf("impossible\n");
        }
    }
    return 0;
}