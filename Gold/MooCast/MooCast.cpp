#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    int n; cin >> n;
    vector<pair<int, int>> coords(n);
    for(auto &p: coords){
        cin >> p.first >> p.second;
    }
    vector<set<pair<int, int>>> distances(n);
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int distance =
                (coords[i].first - coords[j].first) * (coords[i].first - coords[j].first) +
                (coords[i].second - coords[j].second) * (coords[i].second - coords[j].second);
            distances[i].insert({distance, j});
            distances[j].insert({distance, i});
        }
    }

    int low = 0; int high = 2 * 25000 * 25000;
    while(high - low > 0){
        int mid = (high + low) / 2;
        vector<bool> reached(n);
        int cows_reached = 0;
        queue<int> q;
        q.push(0);
        while(q.size()){
            int curr =  q.front();
            q.pop();
            auto it = distances[curr].begin();
            while(it != distances[curr].end() && (*it).first <= mid){
                if(!reached[(*it).second]){
                    q.push((*it).second);
                    reached[(*it).second] = true;
                    cows_reached++;
                }
                it++;
            }
        }
        if(cows_reached == n){
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << low;
}