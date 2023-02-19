#include <iostream>
using namespace std;

int dp[1001][1001] = {0};
int main(){
    freopen ("paintbarn.in", "r", stdin);
    freopen ("paintbarn.out", "w", stdout);

    int n, k; cin >> n >> k;
    
    while(n--){
        int a, b, c, d; cin >> a >> b >> c >> d;
        dp[a][b]++;
        dp[a][d]--;
        dp[c][b]--;
        dp[c][d]++;
    }
    
    int ans = 0;

    for(int x = 1; x < 1000; x++){
        dp[x][0] += dp[x-1][0];
    }
    for(int y = 1; y < 1000; y++){
        dp[0][y] += dp[0][y-1];
    }

    for(int x = 1; x < 1000; x++){
        for(int y = 1; y < 1000; y++){
            dp[x][y] -= dp[x-1][y-1] - dp[x][y-1] - dp[x-1][y];
            if(dp[x][y] == k) ans++;
        }
    }
    cout << ans;
}