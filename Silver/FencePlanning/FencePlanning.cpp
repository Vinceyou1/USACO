#include <bits/stdc++.h>
using namespace std;

struct Rect{
    int x1 = INT32_MAX;
    int y1 = INT32_MAX;
    int x2 = INT32_MIN;
    int y2 = INT32_MIN;
};

int perim(Rect a, Rect b){
    int min_x = min(a.x1, b.x1);
    int max_x = max(a.y2, b.y2);
    int max_y = max(a.x2, b.x2);
    int min_y = min(a.y1, b.y1);
    return 2*(max_x - min_x + max_y - min_y);
}

Rect DFS(int i, Rect r, vector<vector<int>> &connections, vector<bool> &reached, vector<pair<int, int>> &coords, vector<bool> &included){
    included[i] = true;
    if(reached[i]) return r;
    reached[i] = true;
    for(int i: connections[i]){
        r = DFS(i, r, connections, reached, coords, included);
    }
    r.x1 = min(coords[i].first, r.x1);
    r.x2 = max(coords[i].first, r.x2);
    r.y1 = min(coords[i].second,r.y1);
    r.y2 = max(coords[i].second,r.y2);
    return r;
}

int main(){
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> coords(n);
    for(int i = 0; i < n; i++){
        cin >> coords[i].first >> coords[i].second;
    }
    vector<vector<int>> connections(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        connections[a].push_back(b);
        connections[b].push_back(a);
    }

    // Find unknown
    vector<int> unknown;
    for(int i = 0; i < connections.size(); i++){
        if(connections[i].size() == 0) unknown.push_back(i);
    }
    Rect other;
    if(unknown.size() != 0){
        for(int i = 0; i < unknown.size(); i++){
            other.x1 = min(coords[i].first, other.x1);
            other.x2 = max(coords[i].first, other.x2);
            other.y1 = min(coords[i].second, other.y1);
            other.y2 = max(coords[i].second, other.y2);
        }
    }

    vector<bool> included (n);
    int min_perim = INT32_MAX;
    for(int i = 0; i < n; i++){
        if(!included[i] && connections.size() > 0){
            Rect r;
            vector<bool> reached(n);
            r = DFS(i, r, connections, reached, coords, included);
            if(unknown.size() != 0){
                min_perim = min(perim(r, other), min_perim);
            } else {
                min_perim = min(perim(r, r), min_perim);
            }
        }
    }
    cout << min_perim;
}