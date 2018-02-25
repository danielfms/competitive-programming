#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll sz , p, x, i, square, col, line, c;
    ll top_right, top_left, bottom_right, bottom_left;
    while(scanf("%lld %lld", &sz, &p), (sz || p)){
        i = 0;
        x = 1;
        while( x * x < p){
            x += 2; //square
            i += 1; //Counter odd numbers
        }
        square = x * x;
        top_left = square  - 6 * i;
        top_right = square;
        bottom_right = square - 2 * i;
        bottom_left = square - 4 * i;

        if(square == p){
            line = x;
            col = x;
        }else if(p < top_right && p >= bottom_right){
            line = 1 +  abs( p - bottom_right);
            col = x;
        }else if(p < bottom_right && p >= bottom_left){
            line = 1;
            col = 1 + abs( p - bottom_left);
        }else if( p < bottom_left && p >= top_left){
            line = 1 + abs(p - bottom_left);
            col = 1;
        }else{
            line = x;
            col = 1 + abs(p - top_left);
        }
        //correction size of square/sz
        c = abs(sz - x) / 2;
        line += c;
        col += c;

        //printf("IN : %lld %lld | %lld %lld\n", sz, p, i, x);
        printf("Line = %lld, column = %lld.\n", line, col);
    }
    return 0;
}