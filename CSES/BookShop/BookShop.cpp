#include <bits/stdc++.h>
using namespace std;

int dp[1001][100001];

int main(){
    int n, x; cin >> n >> x;
    vector<int> prices;
    vector<int> pages;
    for(int i = 0; i < n; ++i){
        int price; cin >> price;
        prices.push_back(price);
    }
    for(int i = 0; i < n; ++i){
        int page; cin >> page;
        pages.push_back(page);
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= x; ++j){
            dp[i][j] = dp[i - 1][j];
            if(prices[i - 1] <= j){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - prices[i - 1]] + pages[i - 1]);
            }
        }
    }
    cout << dp[n][x];
}