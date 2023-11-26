#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> dp (n + 1, INT32_MAX);
    dp[n] = 0;
    for(int i = n; i > 0; --i){
        if(dp[i] == INT32_MAX) continue;
        vector<int> digits;
        int temp = i;
        while(temp){
            digits.push_back(temp % 10);
            temp /= 10;
        }
        for(int digit: digits){
            dp[i - digit] = min(dp[i - digit], dp[i] + 1);
        }
    }
    cout << dp[0];
}