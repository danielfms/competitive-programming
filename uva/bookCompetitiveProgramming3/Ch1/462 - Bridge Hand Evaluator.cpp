#include <bits/stdc++.h>
using namespace std;

vector<string> split(string s){
    stringstream ss(s);
    string card;
    vector<string> v;
    while(ss >> card){
        v.push_back(card);
    }
    return v;
}
int main(){
    string line;
    while(getline(cin, line)){
        int cont = 0;
        map<char, int> suits, kings, queens, jacks, aces, stopped;
        suits['S'] = 0; suits['H'] = 0; suits['D'] = 0; suits['C'] = 0;
        kings['S'] = 0; kings['H'] = 0; kings['D'] = 0; kings['C'] = 0;
        queens['S'] = 0; queens['H'] = 0; queens['D'] = 0; queens['C'] = 0;
        jacks['S'] = 0; jacks['H'] = 0; jacks['D'] = 0; jacks['C'] = 0;
        aces['S'] = 0; aces['H'] = 0; aces['D'] = 0; aces['C'] = 0;
        stopped['S'] = 0; stopped['H'] = 0; stopped['D'] = 0; stopped['C'] = 0;
        vector<string> cards  = split(line);
        int ignore567 = 0;
        for(int i = 0; i < cards.size(); i++){
            string card = cards[i];
            suits[card[1]] += 1;
            //1.Each ace counts 4 points. Each king counts 3 points. Each queen counts 2 points. Each jack
            //counts one point.
            if(card[0] == 'A'){
                cont += 4;
                aces[card[1]] += 1;
            }else if(card[0] == 'K'){
                cont += 3;
                kings[card[1]] += 1;
            }else if(card[0] == 'Q'){
                cont += 2;
                queens[card[1]] += 1;
            }else if(card[0] == 'J'){
                cont += 1;
                jacks[card[1]] += 1;
            }
        }
        //2.Subtract a point for any king of a suit in which the hand holds no other cards.
        for (map<char,int>::iterator it=kings.begin(); it!=kings.end(); ++it){
            if(it->second == suits[it->first]){
                cont -= it->second;
            }
        }
        
        //3.Subtract a point for any queen in a suit in which the hand holds only zero or one other cards.
        for (map<char,int>::iterator it=queens.begin(); it!=queens.end(); ++it){
            if(suits[it->first] - it->second  <= 1){
                cont -= it->second;
            }
        }
        
        //4.Subtract a point for any jack in a suit in which the hand holds only zero, one, or two other cards.
        for (map<char,int>::iterator it=jacks.begin(); it!=jacks.end(); ++it){
            if(suits[it->first] - it->second  <= 2){
                cont -= it->second;
            }
        }
        
        //5.Add a point for each suit in which the hand contains exactly two cards.
        for (map<char,int>::iterator it=suits.begin(); it!=suits.end(); ++it){
            if(it->second == 2){
                cont += 1;
                ignore567 += 1;
            }
        }
        
        //6.Add two points for each suit in which the hand contains exactly one card.
        for (map<char,int>::iterator it=suits.begin(); it!=suits.end(); ++it){
            if(it->second == 1){
                cont += 2;
                ignore567 += 2;
            }
        }
        
        //7.Add two points for each suit in which the hand contains no cards.
        for (map<char,int>::iterator it=suits.begin(); it!=suits.end(); ++it){
            if(it->second == 0){
                cont += 2;
                ignore567 += 2;
            }
        }


        //Check stopped
        //A suit is stopped if it contains an ace, 
        for (map<char,int>::iterator it=aces.begin(); it!=aces.end(); ++it){
            if(it->second == 1){
                stopped[it->first] = 1;
            }
        }
        //if it contains a king and at least one other card, 
        for (map<char,int>::iterator it=kings.begin(); it!=kings.end(); ++it){
            if(it->second == 1 && suits[it->first] >= 2){
                stopped[it->first] = 1;
            }
        }
        //or if it contains a queen and at least two other cards.
        for (map<char,int>::iterator it=queens.begin(); it!=queens.end(); ++it){
            if(it->second == 1 && suits[it->first] >= 3){
                stopped[it->first] = 1;
            }
        }


        //check no trump
        bool allStopped = true;
        for (map<char,int>::iterator it=stopped.begin(); it!=stopped.end(); ++it){
            if(it->second == 0){
                allStopped = false;
            }
        }
        if(cont < 14){
            printf("PASS\n");
        }else if(cont - ignore567 >= 16 && allStopped == true){
            printf("BID NO-TRUMP\n");
        }else if(cont >= 14){
            int maxi = 0;
            char c;
            for (map<char,int>::iterator it=suits.begin(); it!=suits.end(); ++it){
                if(it->second > maxi){
                    maxi = it->second;
                    c = it->first;
                }else if(it->second == maxi){
                    if(it->first > c){
                        c = it->first;
                    }
                }
            }
            printf("BID %c\n", c);  
        }

    }
    return 0;
}