#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x; cin >> n >> x;
    vector<int> coins(n);
    for(int &i: coins) cin >> i;
    sort(coins.begin(), coins.end());
    vector<int> dp(x + 1);
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        for(int weight = 0; weight <= x; weight++){
            if(weight - coins[i] >= 0){
                dp[weight] += dp[weight - coins[i]];
                dp[weight] %= 1000000007;
            }
        }
    }
    cout << dp[x];
}