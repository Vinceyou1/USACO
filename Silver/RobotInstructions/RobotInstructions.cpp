#include <bits/stdc++.h>
using namespace std;

// not sure if this is really needed
bool comp(const pair<pair<long long, long long>, int> a, const pair<pair<long long, long long>, int> b){
    if(a.first.first == b.first.first){
        return a.first.second < b.first.second;
    } 
    return a.first.first < b.first.first;
}

int main(){
    int n; cin >> n;
    long long target_x, target_y; cin >> target_x >> target_y;
    vector<pair<long long, long long>> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i].first >> nums[i].second;
    }

    vector<pair<pair<long long, long long>, int>> left_sums;
    vector<pair<pair<long long, long long>, int>> right_sums;
    for(int i = 0; i < 1 << ((n + 1) / 2); i++){
        pair<long long, long long> sum = {0, 0};
        int amt = 0;
        for(int j = 0; j < (n + 1) / 2; j++){
            if(i & (1 << j)){
                sum.first += nums[j].first;
                sum.second += nums[j].second;
                amt++;
            }
        }
        left_sums.push_back({sum, amt});
    }

    for(int i = 0; i < 1 << (n / 2); i++){
        pair<long long, long long> sum = {0, 0};
        int amt = 0;
        for(int j = 0; j < n / 2; j++){
            if(i & (1 << j)){
                sum.first += nums[j + (n + 1) / 2].first;
                sum.second += nums[j + (n + 1) / 2].second;
                amt++;
            }
        }
        right_sums.push_back({sum, amt});
    }
    sort(left_sums.begin(), left_sums.end(), comp);
    sort(right_sums.begin(), right_sums.end(), comp);

    vector<int> k(n + 1);
    for(auto sum: left_sums){
        pair<long long, long long> target = {target_x - sum.first.first, target_y - sum.first.second};
        auto upper = upper_bound(right_sums.begin(), right_sums.end(), make_pair(target, 21));
        auto lower = lower_bound(right_sums.begin(), right_sums.end(), make_pair(target, 0));
        while(lower != upper){
            k[sum.second + (*lower).second]++;
            lower++;
        }
    }
    for(int i = 1; i <= n; i++){
        cout << k[i] << endl;
    }
}