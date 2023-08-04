#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> heights(n);
    for(int &i: heights) cin >> i;
    vector<int> dp(n);
    dp[0] = 0; 
    dp[1] = abs(heights[1] - heights[0]);
    for(int i = 2; i < n; i++){
        dp[i] = min(dp[i - 2] + abs(heights[i] - heights[i - 2]), dp[i - 1] + abs(heights[i] - heights[i - 1]));
    }
    cout << dp[n - 1];
}