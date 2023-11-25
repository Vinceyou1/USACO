#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x; cin >> n >> x;
    vector<int> nums(n);
    for(int &i: nums) cin >> i;
    vector<long long> left;
    vector<long long> right;
    for(int i = 0; i < 1 << ((n + 1) / 2); i++){
        long long sum = 0;
        for(int j = 0; j < (n + 1) / 2; j++){
            if(i & 1 << j){
                sum += nums[j];
            }
        }
        left.push_back(sum);
    }
    for(int i = 0; i < 1 << (n / 2); i++){
        long long sum = 0;
        for(int j = 0; j < n / 2; j++){
            if(i & 1 << j){
                sum += nums[j + (n + 1) / 2];
            }
        }
        right.push_back(sum);
    }
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    long long ans = 0;
    for(long long i: left){
        long long comp = x - i;
        auto lower = lower_bound(right.begin(), right.end(), comp);
        auto upper = upper_bound(right.begin(), right.end(), comp);
        ans += upper - lower;
    }
    cout << ans;
}