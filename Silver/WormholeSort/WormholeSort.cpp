#include <bits/stdc++.h>
using namespace std;

int DFS(int curr, int destination, vector<vector<pair<int, int>>> &wormholes, vector<int> &evaluated, vector<bool> &visited){
    if(visited[curr]) return INT32_MIN;
    if(curr == destination) return 0;
    if(evaluated[curr] != 0) return evaluated[curr];
    visited[curr] = true;
    for(auto i: wormholes[curr]){
        int d = DFS(i.first, destination, wormholes, evaluated, visited);
        if(d == INT32_MIN) continue;
        if(d == 0){
            evaluated[curr] = max(i.second, evaluated[curr]);
        } else evaluated[curr] = max(min(i.second, d), evaluated[curr]);
    }
    visited[curr] = false;
    return evaluated[curr];
}

int main(){
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> cows(n);
    for(int i = 0; i < n; i++){
        cin >> cows[i];
        cows[i]--;
    }
    vector<vector<pair<int, int>>> wormholes(n); // destination, width
    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        a--; b--;
        wormholes[a].push_back({b, w});
        wormholes[b].push_back({a, w});
    }

    vector<bool> accounted(n);
    int ans = INT32_MAX;
    for(int i = 0; i < n; i++){
        if(accounted[i] || cows[i] == i) continue;
        vector<int> evaluated(n);
        vector<bool> visited(n);
        ans = min(ans, DFS(i, cows[i], wormholes, evaluated, visited));
    }
    if(ans == INT32_MAX) cout << -1;
    else cout << ans;
}