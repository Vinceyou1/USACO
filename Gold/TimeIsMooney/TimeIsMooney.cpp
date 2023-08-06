#include <bits/stdc++.h>
using namespace std;

int dp[1000][1001]; // Most moonies earned from 
vector<int> roads[1000];
int cities[1000];
int n, m, c;

int DFS(int index, int time){
    if(time > 1000) return INT32_MIN;
    if(dp[index][time] != INT32_MIN) return dp[index][time];
    if(index == 0){
        dp[index][time] = -c * time * time;
    }
    for(int i: roads[index]){
        int res = DFS(i, time + 1);
        dp[index][time] = max(dp[index][time], res);
    }
    dp[index][time] += cities[index];
    return dp[index][time];
}

int main(){
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
    cin >> n >> m >> c;
    for(int i = 0; i < n; i++) cin >> cities[i];
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        roads[a].push_back(b);
    }

    for(int i = 0; i < 1000; i++){
        for(int j = 0; j <= 1000; j++){
            dp[i][j] = INT32_MIN;
        }
    }

    DFS(0, 0);
    cout << dp[0][0];
}