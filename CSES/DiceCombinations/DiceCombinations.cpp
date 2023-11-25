#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<long long> dp(n + 6);
    for(int i = 1; i <= 6; i++){
        dp[i] = 1;
    }
    const int MOD = 1000000007;
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= 6; j++){
            dp[i + j] += dp[i];
            dp[i + j] %= MOD;
        }
    }
    cout << dp[n];
}