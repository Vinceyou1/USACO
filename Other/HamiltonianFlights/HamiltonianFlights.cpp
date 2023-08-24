#include <bits/stdc++.h>
using namespace std;

const int MOD  = 1000000007;
// Flights that visit the cities in bitmask and end at second index
int dp[1 << 20][20];
vector<int> adj[20];
int n;

int fly(int bitmask, int end){
    if ((bitmask & (1 << 0)) == 0) return 0;
    if ((bitmask & (1 << (n - 1))) && bitmask != ((1 << n) - 1)) return 0;

    if(dp[bitmask][end]) return dp[bitmask][end];
    for(int i: adj[end]){
        if(!(bitmask & (1 << i))) continue;
        dp[bitmask][end] += fly(bitmask - (1 << end), i);
        dp[bitmask][end] %= MOD;
    }
    return dp[bitmask][end];
}


int main(){
    int m; cin >> n >> m;
    while(m--){
        int a, b; cin >> a >> b;
        a--; b--;
        if(a == b) continue;
        adj[b].push_back(a);
    }

    dp[1][0] = 1;
    cout << fly((1 << n) - 1, n - 1);
}