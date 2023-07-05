#include <bits/stdc++.h>
using namespace std;



int main(){
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
    int n, b; cin >> n >> b;
    vector<pair<int, pair<int, int>>> heights; // height, then previous and next
    for(int i = 0; i < n; i++){
        int h; cin >> h;
        heights.push_back({h, {i-1, i+1}});
    }
    sort(heights.begin(), heights.end());
    map<int, int> m; // this maps tile coord to index
    for(int i = 0; i < n; i++){
        m[heights[i].second.first + 1] = i;
    }
    // for(auto &i: m){
    //     cout << i.first << " " << i.second << endl;
    // }

    set<pair<int, pair<int, int>>> boots; // snow, distance
    vector<bool> ans(b);
    for(int i = 0; i < b; i++){
        int a, b; cin >> a >> b;
        boots.insert({a, {b, i}});
    }

    int max_distance = 1;
    int height_index = heights.size() - 1;
    for(auto it = --boots.end(); ; it--){
        int snow = (*it).first;
        int distance = (*it).second.first;
        while(heights[height_index].first > snow && height_index >= 0){
            int prev = heights[height_index].second.first;
            int next = heights[height_index].second.second;
            max_distance = max(max_distance, next - prev);
            heights[m[prev]].second.second = next;
            heights[m[next]].second.first = prev;
            height_index--;
        }
        // cout << max_distance << endl;
        if(distance >= max_distance) ans[(*it).second.second] = true;
        else ans[(*it).second.second] = false;
        if(it == boots.begin()) break;
    }
    // cout << endl;
    for(bool i: ans){
        cout << i << "\n";
    }
}