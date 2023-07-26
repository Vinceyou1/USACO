#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>> &paths, vector<int> &component, int index, int component_num){
    component[index] = component_num;
    for(int i: paths[index]){
        if(component[i] == -1){
            DFS(paths, component, i, component_num);
        }
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<vector<int>> paths(n);
        for(int i = 0; i < m; i++){
            int a, b; cin >> a >> b;
            a--; b--;
            paths[a].push_back(b);
            paths[b].push_back(a);
        }
        vector<int> component(n, -1);
        int component_num = 0;
        for(int i = 0; i < n; i++){
            if(component[i] == -1){
                DFS(paths, component, i, component_num);
                component_num++;
            }
        }
        vector<vector<int>> components(component_num);
        for(int i = 0; i < n; i++){
            components[component[i]].push_back(i);
        }

        vector<long long> dist_to_begin(components.size(), 1e9);
        vector<long long> dist_to_end(components.size(), 1e9);
        int begin_index = 0;
        int end_index = 0;
        for(int i = 0; i < n; i++){
            dist_to_begin[component[i]] = min(dist_to_begin[component[i]], (long long) abs(i - components[0][begin_index]));
            if(components[0][begin_index] < i) begin_index++;
            if(begin_index == components[0].size()) begin_index--;
            
            dist_to_end[component[i]] = min(dist_to_end[component[i]], (long long) abs(i - components[component[n - 1]][end_index]));
            if(components[component[n - 1]][end_index] < i) end_index++;
            if(end_index == components[component[n - 1]].size()) end_index--;
        }
        long long ans = LLONG_MAX;
        for(int i = 0; i < components.size(); i++){
            ans = min(ans, dist_to_begin[i]*dist_to_begin[i] + dist_to_end[i]*dist_to_end[i]);
        }
        cout << ans << endl;
    }
}