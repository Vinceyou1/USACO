#include <bits/stdc++.h>
using namespace std;

bool can_reach(pair<long long, long long> start, pair<long long, long long> end, long long delta_x, long long delta_y, long long days, long long len, vector<char> &wind){
    long long cycles = days / len;
    long long x3 = start.first + delta_x * cycles;
    long long y3 = start.second + delta_y * cycles;
    for(int i = 0; i < days - cycles*len; i++){
        switch(wind[i]){
            case 'U':
                y3++;
                break;
            case 'R':
                x3++;
                break;
            case 'D':
                y3--;
                break;
            case 'L':
                x3--;
                break;
        }
    }
    long long distance = abs(end.first - x3) + abs(end.second - y3);
    if(distance <= days) {
        return true;
    }
    else return false;
}

int main(){
    pair<long long, long long> start, end;
    cin >> start.first >> start.second >> end.first >> end.second;
    long long len;
    cin >> len;
    long long delta_x = 0;
    long long delta_y = 0;
    vector<char> wind;
    for(int i = 0; i < len; i++){
        char c; cin >> c;
        wind.push_back(c);
        switch(c){
            case 'U':
                delta_y++;
                break;
            case 'R':
                delta_x++;
                break;
            case 'D':
                delta_y--;
                break;
            case 'L':
                delta_x--;
                break;
        }
    }

    long long days = LONG_LONG_MAX / 2 + 1;
    for(long long d = days / 2; d > 0; d /= 2){
        if(can_reach(start, end, delta_x, delta_y, days - d, len, wind)) {
            days -= d;
        }
        else{
            if(days == LONG_LONG_MAX / 2 + 1){
                cout << "-1";
                return 0;
            }
        }
    }
    cout << days;
}