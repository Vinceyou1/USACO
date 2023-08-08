#include <bits/stdc++.h>
using namespace std;

bool grid[1000][1000];
int dp[1000][1000];
int n;

int main(){
    cin >> n;
    dp[n - 1][n - 1] = 1;
    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            char c; cin >> c;
            grid[x][y] = (c == '.');
        }
    }

    dp[n - 1][n - 1] = grid[n - 1][n - 1];
    for(int x = n - 2; x >= 0; x--){
        if(grid[x][n - 1]){
            dp[x][n - 1] = dp[x + 1][n - 1];
        }
    }
    for(int y = n - 2; y >= 0; y--){
        if(grid[n - 1][y]){
            dp[n - 1][y] = dp[n - 1][y + 1];
        }
    }
    for(int x = n - 2; x >= 0; x--){   
        for(int y = n - 2; y >= 0; y--){
            if(grid[x][y]){
                dp[x][y] += dp[x + 1][y] + dp[x][y + 1];
                dp[x][y] %= 1000000007;
            }
        }
    }
    cout << dp[0][0];
}