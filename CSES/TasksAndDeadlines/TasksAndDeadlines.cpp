#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> tasks; // duration, deadline
    while(n--){
        long long a, b;
        cin >> a >> b;
        tasks.push({a, b});
    }
    long long current_time = 0;
    long long score = 0;
    while(tasks.size()){
        auto top = tasks.top();
        tasks.pop();
        current_time += top.first;
        score += top.second - current_time;
    }
    cout << score;
}