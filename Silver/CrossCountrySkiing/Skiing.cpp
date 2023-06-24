#include <bits/stdc++.h>
using namespace std;

const int MAX_GRID = 500;
int grid[MAX_GRID][MAX_GRID];
int waypoints[MAX_GRID][MAX_GRID];
bool reached[MAX_GRID][MAX_GRID];
int n, m;

int floodfill(int x, int y, int d, int previous){
    if(x < 0 || x >= n || y < 0 || y >= m) return 0;
    if(reached[x][y]) return 0;
    if(abs(previous - grid[x][y]) > d) return 0;
    reached[x][y] = true;
    int point = waypoints[x][y];
    int val = grid[x][y];
    return point + floodfill(x + 1, y, d, val) + floodfill(x - 1, y, d, val) + floodfill(x, y + 1, d, val) + floodfill(x, y - 1, d, val);
}

int main(){
    freopen("ccski.in", "r", stdin);
    freopen("ccski.out", "w", stdout);
    cin >> m >> n;
    for(int y = 0; y < m; y++){
        for(int x = 0; x < n; x++){
            cin >> grid[x][y];
        }
    }
    int points =  0;
    pair<int, int> point = make_pair(-1, -1);
    for(int y = 0; y < m; y++){
        for(int x = 0; x < n; x++){
            cin >> waypoints[x][y];
            if(waypoints[x][y]) {
                points++;
                if(point.first == -1) point = make_pair(x, y); 
            }
        }
    }
    int high = 1000000001;
    int low = 0;
    while(high - low > 0){
        int mid = (high + low) / 2;
        for(auto &i: reached){
            for(auto &j: i){
                j = false;
            }
        }
        int flood = floodfill(point.first, point.second, mid, grid[point.first][point.second]);
        if(flood == points){
            high = mid;
        } else low = mid + 1;
    }
    cout << low;
}