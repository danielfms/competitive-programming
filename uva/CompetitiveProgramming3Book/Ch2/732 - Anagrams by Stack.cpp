#include <bits/stdc++.h>
using namespace std;
string in, target;
void solver(string st, string moves, int c_in, int c_out){
    int len = in.size();
    int len_moves = moves.size();
    if(len_moves == (2 * len)){
        for(int i = 0; i < len_moves - 1; i++){
            cout<<moves[i]<<" ";
        }
        cout<<moves[len_moves - 1]<<"\n";
    }
    
    //in
    string st_copy = st.substr(0, string::npos);
    string moves_copy = moves.substr(0, string::npos);
    if(c_in < len){
        st_copy.push_back(in[c_in]);
        moves_copy.push_back('i');
        //cout<<"in: "<<st_copy << " " << moves_copy <<endl;
        solver(st_copy, moves_copy, c_in + 1, c_out);
    }
    //out
    st_copy = st.substr(0, string::npos);
    moves_copy = moves.substr(0, string::npos);
    if(!st_copy.empty()){
        char c = st_copy.back();
        if (target[c_out] == c){
            st_copy.pop_back();
            moves_copy.push_back('o');
            //cout<<"out: "<<st_copy << " " << moves_copy <<endl;
            solver(st_copy, moves_copy, c_in, c_out + 1);
        }
    }
}
int main(){
    while(cin>>in>>target){
        string st = "", moves = "";
        //cout<<in<<" "<<target <<endl;
        printf("[\n");
        if(in.size() == target.size()){
            solver(st, moves, 0, 0);
        }
        printf("]\n");
    }
    return 0;
}