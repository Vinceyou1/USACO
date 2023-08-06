#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x; cin >> n >> x;
    vector<int> coins(n);
    for(int &i: coins) cin >> i;
    vector<int> dp(x + 1); dp[0] = 1;
    for(int i = 0; i <= x; i++){
        for(int c: coins){
            if(i - c >= 0){
                dp[i] += dp[i - c];
                dp[i] %= 1000000007;

            }
        }
    }
    cout << dp[x];
}