#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> cows(n);
    for(int &i: cows){
        cin >> i;
        i--;
    }
    vector<vector<pair<int, int>>> wormholes(n);

    
    int max_width = 0;
    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        max_width = max(max_width, w);
        a--; b--;
        wormholes[a].push_back({b, w});
        wormholes[b].push_back({a, w});
    }

    // binary search on the possible width
    int left = 0;
    int right = max_width + 1;
    while(right - left > 0){
        int mid = (right + left + 1) / 2;
        vector<int> components(n);
        int component = 1;
        for(int i = 0; i < n; i++){
            queue<int> DFS;
            DFS.push(i);
            while(DFS.size() > 0){
                int top = DFS.front();
                DFS.pop();
                if(components[top] != 0) continue;
                components[top] = component;
                for(auto c: wormholes[top]){
                    if(components[c.first] == 0 && c.second >= mid){
                        // cout << c.first;
                        DFS.push(c.first);
                    }
                }
            }
            component++;
            // cout << "here";
        }
        bool valid = true;
        for(int i = 0; i < n; i++){
            if(i != cows[i]){
                if(components[i] != components[cows[i]] || components[i] == 0){
                    valid = false;
                    break;
                }
            }
        }
        if(valid){
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    if(right == max_width + 1){ cout << -1; return 0; }
    cout << right;
}