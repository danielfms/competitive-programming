#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl
#define MAX 10e6
bool load(queue<int> &q, int l) {
  int current_capacity = 0;
  bool flag = false;
  while (!q.empty()) {
    int c = q.front();
    if (current_capacity + c <= l) {
      flag = true;
      q.pop();
      current_capacity += c;
    } else break;
  }
  return flag;
}

void solver(queue<int> &left, queue<int> &right, int l){
  int times = 0;
  char pos_ferry = 'L';
  while(true){
    bool flag = load(pos_ferry == 'R' ? right : left, l);
    if(flag){
      // ferry moved
      pos_ferry = pos_ferry == 'R' ? 'L' : 'R';
      times += 1;
    }else{
        if(!left.empty() && right.empty()){
          if(pos_ferry == 'R'){
              pos_ferry = 'L';
              times += 1;
            }
        }else if(left.empty() && !right.empty()){
          if(pos_ferry == 'L'){
                pos_ferry = 'R';
                times += 1;
            }
        }
    }
    if(right.empty() and left.empty()){
        break;
    }
  }
  printf("%d\n", times);
}

int main(void) {
  int tc, l, m, k;
  string bank;
  cin>>tc;
  while(tc--){
    queue<int> left, right;
    cin>>l>>m;
    for(int i = 0; i < m; i++){
      cin>>k>>bank;
      if(bank == "right"){
        right.push(k);
      }else{
        left.push(k);
      }
    }
    solver(left, right, l * 100);
  }
  return 0;
}
