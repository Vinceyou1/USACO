#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int main(){
    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);
    vector<pair<int, int>> cows;
    int n;
    cin >> n;
    for(int c = 0; c < n; c++){
        int x, y;
        cin >> x >> y;
        cows.push_back({x, y});
    }
    sort(cows.begin(), cows.end());
    ll max_x = cows[cows.size()-1].first;
    ll min_x = cows[0].first;

    vector<pair<int, int>> left_max_min_y;
    int left_min_y = cows[0].second;
    int left_max_y = cows[0].second;
    for(int c = 0; c < cows.size(); c++){
        int new_y = cows[c].second;
        left_max_y = max(new_y, left_max_y);
        left_min_y = min(new_y, left_min_y);
        left_max_min_y.push_back({left_min_y, left_max_y});
    }

    vector<pair<int, int>> right_max_min_y(cows.size());
    int right_min_y = cows[cows.size()-1].second;
    int right_max_y = cows[cows.size()-1].second;
    for(int c = cows.size() - 1; c >= 0; c--){
        int new_y = cows[c].second;
        right_max_y = max(new_y, right_max_y);
        right_min_y = min(new_y, right_min_y);
        right_max_min_y[c] = {right_min_y, right_max_y};
    }
    ll min_area = LONG_LONG_MAX;
    // iterates using a vertical line separating the areas;
    for(int c = 0; c < cows.size() - 1; c++){
        // tests for overlap 
        if(cows[c].first == cows[c+1].first){
            if((left_max_min_y[c].first <= right_max_min_y[c+1].second && left_max_min_y[c].first >= right_max_min_y[c+1].first) || 
                (left_max_min_y[c].second <= right_max_min_y[c+1].second && left_max_min_y[c].second >= right_max_min_y[c+1].first) ||
                (right_max_min_y[c+1].first >= left_max_min_y[c].first && right_max_min_y[c+1].first <= left_max_min_y[c].second)){
                continue;
            }
        }
        ll area = (cows[c].first - cows[0].first) * (left_max_min_y[c].second - left_max_min_y[c].first) +
            (cows[cows.size()-1].first - cows[c+1].first) * (right_max_min_y[c+1].second - right_max_min_y[c+1].first);
        min_area = min(area, min_area);
    }

    // Now do the same for y

    sort(cows.begin(), cows.end(), cmp);
    ll max_y = cows[cows.size()-1].second;
    ll min_y = cows[0].second;

    vector<pair<int, int>> bottom_max_min_x;
    int bottom_min_x = cows[0].first;
    int bottom_max_x = cows[0].first;
    for(int c = 0; c < cows.size(); c++){
        int new_x = cows[c].first;
        bottom_max_x = max(new_x, bottom_max_x);
        bottom_min_x = min(new_x, bottom_min_x);
        bottom_max_min_x.push_back({bottom_min_x, bottom_max_x});
    }

    vector<pair<int, int>> top_max_min_x(cows.size());
    int top_min_x = cows[cows.size()-1].first;
    int top_max_x = cows[cows.size()-1].first;
    for(int c = cows.size() - 1; c >= 0; c--){
        int new_x = cows[c].first;
        top_max_x = max(new_x, top_max_x);
        top_min_x = min(new_x, top_min_x);
        top_max_min_x[c] = {top_min_x, top_max_x};
    }

    // iterates using a horizontal line separating the areas;
    for(int c = 0; c < cows.size() - 1; c++){
        // tests for overlap 
        if(cows[c].second == cows[c+1].second){
            if((bottom_max_min_x[c].first <= top_max_min_x[c+1].second && bottom_max_min_x[c].first >= top_max_min_x[c+1].first) || 
                (bottom_max_min_x[c].second <= top_max_min_x[c+1].second && bottom_max_min_x[c].second >= top_max_min_x[c+1].first) || 
                (top_max_min_x[c+1].first >= bottom_max_min_x[c].first && top_max_min_x[c+1].first <= bottom_max_min_x[c].second)){
                continue;
            }
        }
        ll area = (cows[c].second - cows[0].second) * (bottom_max_min_x[c].second - bottom_max_min_x[c].first) +
            (cows[cows.size()-1].second - cows[c+1].second) * (top_max_min_x[c+1].second - top_max_min_x[c+1].first);
        min_area = min(area, min_area);
    }

    cout << (max_x - min_x) * (max_y - min_y) - min_area;
}