#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<vector<pair<int, int>>> s;
    int size;
    DSU(int n) {
        s = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(n, {-1, -1}));
        size = n;
    }

    pair<int, int> repr(pair<int, int> coord){
        if(s[coord.first][coord.second].first < 0) return coord;
        s[coord.first][coord.second] = repr(s[coord.first][coord.second]);
        return s[coord.first][coord.second];
    }

    bool unite(pair<int, int> a, pair<int, int> b){
        a = repr(a); b = repr(b);
        if(a.first == b.first && a.second == b.second) return false;
        if(s[a.first][a.second].first < s[b.first][b.second].first){
            swap(a, b);
        }
        s[b.first][b.second].first += s[a.first][a.second].first;
        s[a.first][a.second] = b;
        return -s[b.first][b.second].first >= ((size * size + 1) / 2);
    }
};

int main(){
    freopen("tractor.in", "r", stdin);
    int n; cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            cin >> grid[r][c];
        }
    }

    vector<tuple<int, pair<int, int>, pair<int, int>>> connections; // difference, then point a, point b 

    for(int r = 0; r < n; r += 1){
        for(int c = r % 2; c < n; c += 2){
            auto p = make_pair(r, c);
            if(r > 0) {
                connections.push_back({abs(grid[r - 1][c] - grid[r][c]), p, {r - 1, c}});
            }
            if(r < n - 1) {
                connections.push_back({abs(grid[r + 1][c] - grid[r][c]), p, {r + 1, c}});
            }
            if(c > 0) {
                connections.push_back({abs(grid[r][c - 1] - grid[r][c]), p, {r, c - 1}});
            }
            if(c < n - 1) {
                connections.push_back({abs(grid[r][c + 1] - grid[r][c]), p, {r, c + 1}});
            }
        }
    }

    DSU dsu(n);

    sort(connections.begin(), connections.end());
    int d = 0;
    for(int i = 0; i < connections.size(); i++) {
        d = get<0>(connections[i]);
        if(dsu.unite(get<1>(connections[i]), get<2>(connections[i]))) break;
    }
    freopen("tractor.out", "w", stdout);
    cout << d;
}