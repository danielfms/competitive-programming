#include <bits/stdc++.h>
//http://codeforces.com/contest/612/problem/C
//C. Replace To Make Regular Bracket Sequence
using namespace std;



int main(){
    stack<char> st;
    string s;
    char open;
    
    map<char, char> cc;
    cc['>'] = '<';
    cc['}'] = '{';
    cc[')'] = '(';
    cc[']'] = '[';
    
    cin>>s;
    int len=s.size(),cont=0;
    
    if(len%2!=0){
        cout<<"Impossible"<<endl;
        return 0;
    }
    for(int i=0;i<len;i++){
        if(s[i] == '<' || s[i] == '{' || s[i] == '[' || s[i] == '('){
            st.push(s[i]);   
        }else{
            if(st.empty()){
                cout<<"Impossible"<<endl;
                return 0; 
            }
            open = st.top();
            st.pop();
            if(cc[s[i]]!=open) cont+=1;
        }
    }
    if(st.empty())
        cout<<cont<<endl;
    else
        cout<<"Impossible"<<endl; 
    
    return 0;
}