#include <bits/stdc++.h>
using namespace std;
#define MAX 2504
#define EPS 1e-5
double f[MAX];

void init(){
  f[1] = 0.0;
  for(int i=2; i < MAX; i++)
    f[i] = f[i-1] + log(double(i));
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int cases, lenA, lenB, lenC, num, c=1;
  double fA = 0.0, fB = 0.0, fC = 0.0;
  cin >> cases;
  init(); // calcula suma de logaritmos
  while (cases--) {
    fA = 0.0, fB = 0.0, fC = 0.0;
    vector< pair<double, char> > fs;
    cin >> lenA >> lenB >> lenC;
    for (int i = 0; i < lenA; i++) {
      cin >> num;
      fA += f[num];
    }
    fs.push_back(make_pair(fA, 'A'));
    for (int i = 0; i < lenB; i++) {
      cin >> num;
      fB += f[num];
    }
    fs.push_back(make_pair(fB, 'B'));
    for (int i = 0; i < lenC; i++) {
      cin >> num;
      fC += f[num];
    }
    fs.push_back(make_pair(fC, 'C'));

    sort(fs.begin(), fs.end());
    cout<< "Case #"<< c++ <<": ";
    if(fs[2].first - fs[1].first > EPS )
      cout<< fs[2].second <<endl;
    else cout<< "TIE"  << endl;
    //cout << fA << " " << fB << " " << fC << endl;
  }
  return 0;
}
