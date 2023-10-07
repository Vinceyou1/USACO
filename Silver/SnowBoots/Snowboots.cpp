#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 250;
int n, b;
vector<int> tiles;
vector<pair<int, int>> boots; // snow depth and max step size 
int dp[MAX_N][MAX_N];

int solve(int tile, int boot){
    if(tile == n - 1) return boot;
    if(dp[tile][boot]) return dp[tile][boot];
    dp[tile][boot] = b;
    for(int i = tile + 1; i < min(boots[boot].second + tile + 1, n); ++i){
        if(tiles[i] <= boots[boot].first){
            dp[tile][boot] = min(dp[tile][boot], solve(i, boot));
        }
    }
    for(int i = boot + 1; i <= b; ++i) {
        if(boots[i].first >= tiles[tile]){
            dp[tile][boot] = min(dp[tile][boot], solve(tile, i));
        }
    }
    return dp[tile][boot];
}

int main()
{
    freopen("snowboots.in", "r", stdin);
    cin >> n >> b;
    for(int i = 0; i < n; ++i) {
        int depth; cin >> depth;
        tiles.push_back(depth);
    }
    boots.push_back({0, 0}); // literally just so i can use boot to be 1-indexed
    for(int i = 0; i < b; ++i) {
        pair<int, int> boot;
        cin >> boot.first >> boot.second;
        boots.push_back(boot);
    }

    freopen("snowboots.out", "w", stdout);
    cout << solve(0, 1) - 1;
}