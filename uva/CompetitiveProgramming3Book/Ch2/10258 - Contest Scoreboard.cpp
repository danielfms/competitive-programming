#include <bits/stdc++.h>
using namespace std;
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

#define MAX 2000000000

int main(){
    int n, contestant, problem, penalty_time;
    string s, L;
    stringstream  ss;
    getline(cin, s);
    ss << s;
    ss >> n;
    getline(cin, s);
    while(n--){
        map<int,Team> scores;
        map<int, map<int, int> > contestant_penalty;
        while(true){
            getline(cin, s);
            if(s.empty()){
                break;
            }
            ss.clear();
            ss << s;
            ss >> contestant;
            ss >> problem;
            ss >> penalty_time;
            ss >> L;
            
            if(contestant_penalty.count(contestant) == 0){
                map<int, int> problems_penalty;
                contestant_penalty[contestant] = problems_penalty;
                //penalty
                contestant_penalty[contestant][problem] = 0;
                //counter incorrect
                contestant_penalty[contestant][problem + 10] = 0;
                //counter solved problem
                contestant_penalty[contestant][problem + 20] = 0;
            }

            if(scores.count(contestant) == 0){
                Team t;
                t.team_number = contestant;
                t.penalty_time = 0;
                t.resolved = 0;
                scores[contestant] = t;
            }  
            map<int, int> cp = contestant_penalty[contestant];
            if(L == "C" || L == "I"){
                if(L == "C"){
                    cp[problem] = cp[problem + 20] == 0 ? penalty_time : min(penalty_time, cp[problem]);
                    cp[problem + 20] += 1;
                }else if(L == "I"){
                    cp[problem + 10] += 1;
                    //printf("D: %d %d %d\n",contestant, problem, cp[problem + 10]);
                }
                
                if(L == "C" && cp[problem + 20] == 1){
                    Team t;
                    t = scores[contestant];
                    t.penalty_time += (cp[problem] + (20 * cp[problem + 10]));
                    t.resolved += 1;
                    scores[contestant] = t;
                }
                contestant_penalty[contestant] = cp; 
            }
        } 
        vector<Team> v;
        for (auto &[k, vv] : scores ){
            v.push_back(vv);
        }
        sort(v.begin(), v.end());
        for (auto &i : v ){
             printf("%d %d %d\n", i.team_number, i.resolved, i.penalty_time);
        }
        if(n > 0){
            printf("\n");
        }
    }
   
    return 0;
}