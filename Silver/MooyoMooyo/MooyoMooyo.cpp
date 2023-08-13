#include <bits/stdc++.h>
using namespace std;

vector<int> grid[10];
vector<int> visited[10];

int fill(int row, int col, int num){
    if(col < 0 || col >= 10) return 0;
    if(row < 0 || row >= grid[col].size()) return 0;
    if(grid[col][row] != num) return 0;
    if(visited[col][row]) return 0;
    int ans = 1;
    visited[col][row] = true;
    ans += fill(row + 1, col, num);
    ans += fill(row - 1, col, num);
    ans += fill(row, col + 1, num);
    ans += fill(row, col - 1, num);
    return ans;
}

void clear(int row, int col, int num){
    if(col < 0 || col >= 10) return;
    if(row < 0 || row >= grid[col].size()) return;
    if(grid[col][row] != num) return;
    grid[col][row] = 0;
    clear(row + 1, col, num);
    clear(row - 1, col, num);
    clear(row, col + 1, num);
    clear(row, col - 1, num);
}

int main(){
    freopen("mooyomooyo.in", "r", stdin);
    freopen("mooyomooyo.out", "w", stdout);
    int n, k; cin >> n >> k;
    for(int i = 0; i < 10; i++){
        grid[i].resize(n);
        visited[i].resize(n);
    }
    for(int row = n - 1; row >= 0; row--){
        for(int col = 0; col < 10; col++){
            char c; cin >> c;
            grid[col][row] = c - '0';
        }
    }
    bool cont = true;
    while(cont){
        for(int col = 0; col < 10; col++){
            for(int row = 0; row < grid[col].size(); row ++){
                if(grid[col][row]){
                    int num = fill(row, col, grid[col][row]);
                    if(num >= k) clear(row, col, grid[col][row]);
                }
            }
        }
        bool temp = false;
        for(int col = 0; col < 10; col++){
            for(int i = 0; i < grid[col].size();){
                if(!grid[col][i]){
                    grid[col].erase(grid[col].begin() + i);
                    temp = true;
                } else {
                    i++;
                }
            }
        }

        for(int col = 0; col < 10; col++){
            for(int i = 0; i < grid[col].size(); i++){
                visited[col][i] = false;
            }
        }
        cont = temp;
    }
    for(int row = n - 1; row >= 0; row--){
        for(int col = 0; col < 10; col++){
            if(row >= grid[col].size()) cout << 0;
            else cout << grid[col][row];
        }
        cout << endl;
    }
    
}