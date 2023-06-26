#include <bits/stdc++.h>
using namespace std;
bool roads[100][100][100][100]; // x1, y1, x2, y2
bool visited[100][100];
int n;
struct cow{
    int x, y;
};

void clear(){
    for(auto &i: visited){
        for(auto &j: i){
            j = false;
        }
    }
}

bool DFS(cow a, cow b, int x, int y, int x_prev, int y_prev){
    if(x < 0 || x >= n || y < 0 || y >= n) return false;
    if(visited[x][y]) return false;
    if(roads[x][y][x_prev][y_prev]) return false; 
    if(x == b.x && y == b.y) return true;
    visited[x][y] = true;
    return (DFS(a, b, x + 1, y, x, y) || DFS(a, b, x - 1, y, x, y) || DFS(a, b, x, y + 1, x, y) || DFS(a, b, x, y - 1, x, y));
}

int main(){
    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);
    int k, r;
    cin >> n >> k >> r;
    while(r--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;
        roads[x1][y1][x2][y2] = true;
        roads[x2][y2][x1][y1] = true;
    }
    vector<cow> cows(k);
    for(auto &i: cows){
        cin >> i.x >> i.y;
        i.x--; i.y--;
    }
    int distant = 0;
    for(int i = 0; i < k; i++){
        for(int j = i + 1; j < k; j++){
            clear();
            if(!DFS(cows[i], cows[j], cows[i].x, cows[i].y, cows[i].x, cows[i].y)) distant++;
        }
    }
    cout << distant;
}