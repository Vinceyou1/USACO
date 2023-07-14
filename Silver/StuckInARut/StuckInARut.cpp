#include <bits/stdc++.h>
using namespace std;

bool y_cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
    return a.first.second < b.first.second;
}

int main(){
    int n; cin >> n;
    vector<pair<int, int>> all;
    vector<pair<pair<int, int>, int>> north;
    vector<pair<pair<int, int>, int>> east;
    for(int i = 0; i < n; i++){
        char direction; cin >> direction;
        int x, y; cin >> x >> y;
        if(direction == 'N') north.push_back({{x, y}, i});
        else east.push_back({{x, y}, i});
        all.push_back({x, y});
    }
    sort(north.begin(), north.end());
    sort(east.begin(), east.end(), y_cmp);
    vector<int> blocked_by(n, -1);
    for(int i = 0; i < north.size(); i++){
        for(int j = 0; j < east.size(); j++){
            if(blocked_by[east[j].second] >= 0) continue;
            int north_x = north[i].first.first;
            int north_y = north[i].first.second;
            int east_x = east[j].first.first;
            int east_y = east[j].first.second;
            if(north_x >= east_x && north_y <= east_y){
                int north_index = north[i].second;
                int east_index = east[j].second;
                int north_time = east_y - north_y;
                int east_time = north_x - east_x;
                if(north_time > east_time) {blocked_by[north_index] = east_index; break;}
                if(east_time > north_time) {blocked_by[east_index] = north_index;}
            }
        }
    }
    for(int i = 0; i < east.size(); i++){
        for(int j = 0; j < north.size(); j++){
            if(blocked_by[north[j].second] >= 0){
                auto block = blocked_by[north[j].second];
                // cout << north[j].second << " " << blocked_by[north[j].second] << endl;
                if(all[block].second <= east[i].first.second) continue;
            }
            int north_x = north[j].first.first;
            int north_y = north[j].first.second;
            int east_x = east[i].first.first;
            int east_y = east[i].first.second;
            if(north_x >= east_x && north_y <= east_y){
                int north_index = north[j].second;
                int east_index = east[i].second;
                int north_time = east_y - north_y;
                int east_time = north_x - east_x;
                if(north_time > east_time) {blocked_by[north_index] = east_index;}
                if(east_time > north_time) {blocked_by[east_index] = north_index; break;}
            }
        }
    }
    vector<int> blame(n);
    for(int i = 0; i < blocked_by.size(); i++){
        int temp = i;
        while(blocked_by[temp] != -1){
            temp = blocked_by[temp];
            blame[temp]++;
        }
    }
    for(auto i: blame){
        cout << i << endl;
    }
}