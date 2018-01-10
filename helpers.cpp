#include <bits/stdc++.h>

struct Team{
    int team_number;
    int resolved;
    int penalty_time;

    bool operator<(const Team &rhs) const {
        if(resolved != rhs.resolved){
        return resolved  > rhs.resolved ; 
        }
        if(penalty_time != rhs.penalty_time){
            return penalty_time < rhs.penalty_time; 
        }
        return team_number < rhs.team_number;
    }
    bool operator==(const Team &rhs) const {
        return team_number == rhs.team_number;
    }
};

vector<int> split(string s){
    vector<int> v;
    stringstream ss(s);
    int token;
    while (ss >> token){
        v.push_back(token);
    }
    return v;
}

//digits in binary of decimal
//digits = floor(log2(n)) + 1;