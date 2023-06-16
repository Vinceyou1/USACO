#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    set<pair<int, int>> tasks; // duration, deadline
    while(n--){
        long long a, b;
        cin >> a >> b;
        tasks.insert({a, b});
    }
    auto it = tasks.begin();
    unsigned long long current_time = 0;
    long long score = 0;
    while(it != tasks.end()){
        current_time += (*it).first;
        score += (*it).second;
        score -= current_time;
        it++;
    }
    cout << score;
}