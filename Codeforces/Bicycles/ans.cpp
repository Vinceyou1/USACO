#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<vector<pair<int, int>>> edges(n);
        for(int i = 0; i < m; ++i){
            int u, v, w; cin >> u >> v >> w;
            u--; v--;
            edges[u].push_back({v, w});
            edges[v].push_back({u, w});
        }
        vector<int> slowness(n);
        for(int &i: slowness) cin >> i;
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>> > pq; // current time, then index, then current speed
        vector<vector<long long>> dp(n, vector<long long>(1001, LLONG_MAX)); // time to reach node, then speed
        pq.push({0, 0, slowness[0]});
        vector<vector<bool>> visited(n, vector<bool>(1001, false));
        dp[0][slowness[0]] = 0;
        while(pq.size()){
            auto t = pq.top();
            pq.pop();
            long long time = get<0>(t);
            int index = get<1>(t);
            int speed = get<2>(t);
            if(visited[index][speed]) continue;
            visited[index][speed] = true;
            for(auto p: edges[index]){
                int temp_speed = min(speed, slowness[p.first]);
                long long new_time = time + 1LL * speed * p.second;
                if(visited[p.first][temp_speed] || dp[p.first][temp_speed] <= new_time) continue;
                dp[p.first][temp_speed] = new_time;
                pq.push({new_time, p.first, temp_speed});
            }
        }
        long long ans = LLONG_MAX;
        for(long long i: dp[n - 1]){
            ans = min(ans, i);
        }
        cout << ans << endl;
    }
}