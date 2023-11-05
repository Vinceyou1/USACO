#include <bits/stdc++.h>
using namespace std;

int solve(int index, vector<bool> &visited, vector<vector<int>> &connections);

int main()
{
    int n; cin >> n;
    vector<vector<int>> connections(n);
    for(int i = 1; i < n; ++i){
        int a, b; cin >> a >> b;
        a--; b--;
        connections[a].push_back(b);
        connections[b].push_back(a);
    }
    int days = 0;
    vector<bool> visited(n);
    cout << solve(0, visited, connections);
}

int solve(int index, vector<bool> &visited, vector<vector<int>> &connections)
{
    int ans = 0;
    visited[index] = true;
    vector<int> to_visit;
    for(int i: connections[index]){
        if(!visited[i]){
            to_visit.push_back(i);
        }
    }
    int curr_cows = 1;
    while(curr_cows - 1 < to_visit.size()){
        curr_cows *= 2;
        ++ans;
    }
    for(int i: to_visit){
        ++ans;
        ans += solve(i, visited, connections);
    }
    return ans;
}