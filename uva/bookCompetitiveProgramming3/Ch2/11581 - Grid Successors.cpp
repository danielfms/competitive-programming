#include <bits/stdc++.h>
using namespace std;
int grid[5][5], grid_temp[5][5];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool fg(){
    bool zeros = true;
    //check zeros
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 3; j++){
            if(grid[i][j] != 0){
                zeros = false;
            }
        }
    }
    if(!zeros){
        memset(grid_temp, 0, sizeof grid_temp);
        for(int i = 1; i <= 3; i++){
            for(int j = 1; j <= 3 ; j++){
                int sum = 0;
                for(int k = 0; k < 4; k++){
                    sum += grid[i + dx[k]][j + dy[k]];
                }
                grid_temp[i][j] = sum % 2;
            }
        }
        //copy
        for(int i = 1; i <= 3; i++){
            for(int j = 1; j <= 3; j++){
                //printf("%d", grid_temp[i][j]);
                grid[i][j] = grid_temp[i][j];
            }
            //printf("\n");
        }
    }

    return zeros;
}

void solver(){
    int index = -1;
    while(!fg()){
        index++;
    }
    printf("%d\n", index);
}


int main(){
    int k;
    string line;
    stringstream ss;
    getline(cin, line);
    ss << line;
    ss >> k;
    while(k--){
        getline(cin, line);
        memset(grid, 0, sizeof grid);
        for(int i = 1; i <= 3; i++){
            getline(cin, line);
            for(int j = 1; j <= 3; j++){
                grid[i][j] = line[j - 1] - 48;
            }
        }
        solver();
    }
    return 0;
}