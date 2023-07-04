#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1000000007;
vector<long long> nums;

long long solve(){
    if(nums.size() == 1) return nums[0] % MOD;
    priority_queue<pair<long long, pair<long long, long long>>, vector<pair<long long, pair<long long, long long>>>, greater<pair<long long, pair<long long, long long>>>> pq;
    int mod = (nums[0] + nums[1]) / MOD;
    for(long long i = 0; i < nums.size() - 1; i++){
        pq.push({nums[i] + nums[i + 1] - mod*MOD, {i, i+1}});
    }
    vector<long long> f;
    while(f.size() < nums.size() - 1){
        f.push_back(pq.top().first);
        long long a = pq.top().second.first; long long b = pq.top().second.second; b++;
        pq.pop(); 
        if(b < nums.size()){
            pq.push({nums[a] + nums[b] - mod*MOD, {a, b}});
        }
    }
    nums = f;
    return solve();
}

int main(){
    long long n; cin >> n;
    nums.resize(n);
    for(auto &i: nums){
        cin >> i;
    }
    sort(nums.begin(), nums.end());
    cout << solve();
}