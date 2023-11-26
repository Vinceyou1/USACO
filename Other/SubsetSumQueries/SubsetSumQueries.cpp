#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;

int main(){
    int q, k; cin >> q >> k;
    vector<int> dp(k + 1);
    dp[0] = 1;
    while(q--){
        char op; cin >> op;
        int x; cin >> x;
        if(op == '+'){
            for(int i = dp.size() - 1; i >= 0; --i){
                if(dp[i] && i + x <= k){
                    dp[i + x] += dp[i];
                    dp[i + x] %= MOD;
                }
            }
        } else {
            for(int i = 1; i < dp.size(); ++i){
                if(i - x >= 0 && dp[i - x]){
                    dp[i] -= dp[i - x];
                    dp[i] += MOD;
                    dp[i] %= MOD;
                }
            }
        }
        cout << dp[k] << endl;
    }
}