#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl
#define MAX 10e6
bool load(queue<pair<int,int> > &q, vector<pair<int, int> > &ans, int capacity, int t, int elapsed) {
  int current_capacity = 0;
  bool flag = false;
  while (!q.empty()) {
    int c = q.front().second;
    if (c <= elapsed and current_capacity < capacity) {
      flag = true;
      ans.push_back(make_pair(q.front().first, elapsed + t));
      q.pop();
      current_capacity += 1;
    } else break;
  }
  return flag;
}

void solver(queue<pair<int,int> > &left, queue<pair<int,int> > &right, int t, int n){
  int et = 0;
  char pos_ferry = 'L';
  vector<pair<int, int> > ans;
  while(true){
    bool flag = load(pos_ferry == 'R' ? right : left, ans, n, t, et);
    if(flag){
      et += t; // ferry moved
      pos_ferry = pos_ferry == 'R' ? 'L' : 'R';
    }else{
        int cr, cl, k;
        cr = !right.empty() ? right.front().second : MAX;
        cl = !left.empty() ? left.front().second : MAX;
        if(!left.empty() && right.empty()){
          k = 1;
        }else if(left.empty() && !right.empty()){
          k = 2;
        }else if(!left.empty() && !right.empty()){
          k = 0;
        }
        if(k == 1 || (k == 0 && cl < cr)){
            if(pos_ferry == 'R'){
              et = max(et + t, cl + t);
              pos_ferry = 'L';
            }else{
              et = max(cl, et);
              pos_ferry = 'L';
            }   
        }else if(k == 2 || (k == 0 && cl > cr)){
            if(pos_ferry == 'R'){
                et = max(et, cr);
                pos_ferry = 'R';
            }else{
                et = max(et + t, cr + t);
                pos_ferry = 'R';
            }  
        }else if(k == 0 && cl == cr){
          et = max(et, pos_ferry == 'R' ? cr : cl);
        }
    }
    if(right.empty() and left.empty()){
        break;
    }
  }
  sort(ans.begin(), ans.end());
  for(int i = 0; i < ans.size(); i++){
    printf("%d\n", ans[i].second);
  }
}

int main(void) {
  int tc, n, t, m, k;
  string bank;
  cin>>tc;
  while(tc--){
    queue<pair<int, int> > left, right;
    cin>>n>>t>>m;
    for(int i = 0; i < m; i++){
      cin>>k>>bank;
      if(bank == "right"){
        right.push(make_pair(i, k));
      }else{
        left.push(make_pair(i, k));
      }
    }
    solver(left, right, t, n);
    if(tc > 0){
      printf("\n");
    }
  }
  return 0;
}
