#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    int available_towers = m;
    queue<pair<int, int>> new_towers; // stored by cow value, then the number of towers they take up
    vector<pair<int, int>> cows(n);
    for(auto &p: cows) cin >> p.first >> p.second;
    sort(cows.begin(), cows.end(), greater<pair<int, int>>());
    long long ans = 0;
    for(int i = 0; i < n; i++){
        int weight = cows[i].first;
        int number = cows[i].second;
        while(new_towers.size()){
            auto p = new_towers.front();
            if(p.first - weight >= k){
                available_towers += p.second;
                new_towers.pop();
            } else break;
        }

        int number_put = min(number, available_towers);
        ans += number_put;
        available_towers -= number_put;
        new_towers.push(make_pair(weight, number_put));
    }
    cout << ans;
}