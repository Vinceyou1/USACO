#include <bits/stdc++.h>
using namespace std;

int depth(vector<vector<int>> &subs, int i, vector<int> &max_depth){
    if(subs[i].size() == 0){
        return 0;
    }
    int m = 0;
    for(int j: subs[i]){
        m = max(m, depth(subs, j, max_depth));
    }
    max_depth[i] = m + 1;
    return m + 1;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> superior(n);
        vector<vector<int>> subs(n);
        superior[0] = -1;
        for(int i = 1; i < n; ++i) {
            cin >> superior[i];
            superior[i]--;
            subs[superior[i]].push_back(i);
        }
        vector<int> max_depth(n); // basically, how long is the longest successor chain, this might be good for greedy?
        depth(subs, 0, max_depth);
        priority_queue<pair<int, int>> pq; // will store max_depth, then the index
        int ans = 0;
        pq.push({max_depth[0], 0});
        while(pq.size()){
            if(pq.size() == 1){
                auto t = pq.top();
                pq.pop();
                for(int i: subs[t.second]){
                    pq.push({max_depth[i], i});
                }
                continue;
            }
            auto t1 = pq.top(); pq.pop();
            auto t2 = pq.top(); pq.pop();
            ans++;
            for(int i: subs[t1.second]){
                pq.push({max_depth[i], i});
            }
            for(int i: subs[t2.second]){
                pq.push({max_depth[i], i});
            }
        }
        cout << ans << endl;
    }
}