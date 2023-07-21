#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<int, int>> patches;
vector<int> nhoj;

int main(){
    // freopen("5.in", "r", stdin);
    // freopen("5.out", "w", stdout);
    int k, m, n; cin >> k >> m >> n;
    patches.resize(k);
    for(int i = 0; i < k; i++){
        cin >> patches[i].first >> patches[i].second;
    }
    sort(patches.begin(), patches.end());
    nhoj.resize(m);
    for(int i = 0; i < m; i++){
        cin >> nhoj[i];
    }
    sort(nhoj.begin(), nhoj.end());
    vector<vector<pair<int, int>>> intervals;
    // bool front_capped = nhoj[0] < patches[0].first; bool end_capped = nhoj[nhoj.size() - 1] > patches[patches.size() - 1].first;
    int patch_index = 0; int nhoj_index = 0;

    while(patch_index < k){
        vector<pair<int, int>> temp;
        while(patch_index < k && nhoj[nhoj_index] > patches[patch_index].first){
            temp.push_back(patches[patch_index]);
            patch_index++;
        } if (temp.size()){
            intervals.push_back(temp);
        }
        nhoj_index++;
    }

    priority_queue<ll> tasty_increases;
    for(int i = 0; i < intervals.size(); i++){
        ll total = 0;
        for(int j = 0; j < intervals[i].size(); j++){
            total += intervals[i][j].second;
        }
        // uses inefficient approach, could be done linearly w/out find function in the interval initialization
        int right_nhoj_index = lower_bound(nhoj.begin(), nhoj.end(), intervals[i][0].first) - nhoj.begin();
        if(right_nhoj_index == 0 || right_nhoj_index == k - 1){
            tasty_increases.push(total);
        } else{
            ll max_tasty = 0;
            int left = 0; int right = 0;
            ll curr_tasty = intervals[i][0].second;
            while(left < intervals[i].size()){
                int distance = intervals[i][right].first - intervals[i][left].first;
                int total_space = nhoj[right_nhoj_index] - nhoj[right_nhoj_index - 1];
                if(distance * 2 < total_space) {
                    max_tasty = max(max_tasty, curr_tasty);
                    right++; if(right == intervals[i].size()) break;
                    curr_tasty += intervals[i][right].second;
                } else {curr_tasty -= intervals[i][left].second; left++;}
            }
            tasty_increases.push(max_tasty);
            tasty_increases.push(total - max_tasty);
        }
    }
    ll total_tasty = 0;
    // while(tasty_increases.size()){
    //     cout << tasty_increases.top() << " ";
    //     tasty_increases.pop();
    // }
    while(n){
        if(tasty_increases.size() == 0){
            break;
        }
        total_tasty += tasty_increases.top();
        tasty_increases.pop();
        n--;
    }
    cout << total_tasty;
}