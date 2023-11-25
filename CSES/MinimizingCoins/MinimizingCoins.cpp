#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x; cin >> n >> x;
    vector<int> coins(n);
    for(int &i: coins) cin >> i;

    vector<int> dp(x + 1); dp[0] = 0;
    for(int i = 1; i <= x; i++){
        int m = INT32_MAX;
        for(int coin: coins){
            if(i - coin >= 0 && dp[i - coin] != -1){
                m = min(m, dp[i - coin] + 1);
            }
        }
        if(m == INT32_MAX) dp[i] = -1;
        else dp[i] = m;
    }

    cout << dp[x];
}