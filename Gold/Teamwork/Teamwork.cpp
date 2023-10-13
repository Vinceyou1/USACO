#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("teamwork.in", "r", stdin); 
    freopen("teamwork.out", "w", stdout);
    int n, k; cin >> n >> k;
    vector<int> nums(n);
    for(int &num: nums) cin >> num;
    vector<int> dp(n + 1);
    for(int i = 0; i < n; ++i){
        int max_on_array = 0;
        for(int j = 1; i - j + 1 >= 0 && j <= k; ++j){
            max_on_array = max(max_on_array, nums[i - j + 1]);
            dp[i + 1] = max(dp[i + 1], dp[i - j + 1] + j * max_on_array);
        }
    }
    cout << dp[n];
}