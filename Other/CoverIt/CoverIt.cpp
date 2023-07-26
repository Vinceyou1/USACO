#include <bits/stdc++.h>
using namespace std;

void DFS(vector<bool> &visited, vector<bool> &selected, int index, bool select, vector<vector<int>> &connections){
    selected[index] = select;
    visited[index] = true;
    for(int i: connections[index]){
        if(!visited[i]) DFS(visited, selected, i, !select, connections);
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<vector<int>> connections(n);
        while(m--){
            int a, b; cin >> a >> b;
            a--; b--;
            connections[a].push_back(b);
            connections[b].push_back(a);
        }
        vector<bool> selected(n);
        vector<bool> visited(n);
        DFS(visited, selected, 0, true, connections);
        int amt = 0;
        for(bool i: selected){
            amt += i;
        }
        if(amt <= n / 2){
            cout << amt << endl;
            for(int i = 0; i < n; i++){
                if(selected[i]) cout << i + 1 << " ";
            }
        } else {
            cout << n - amt << endl;
            for(int i = 0; i < n; i++){
                if(!selected[i]) cout << i + 1 << " ";
            }
        }
        cout << endl;
    }
}