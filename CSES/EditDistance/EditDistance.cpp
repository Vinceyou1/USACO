#include <bits/stdc++.h>
using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    vector<vector<int>> grid(a.size() + 1, vector<int>(b.size() + 1, INT32_MAX));

    grid[0][0] = 0;

    for(int i = 0; i <= a.size(); i++){
        for(int j = 0; j <= b.size(); j++){
            if(i < a.size()){
                grid[i + 1][j] = min(grid[i + 1][j], grid[i][j] + 1);
            }
            if(j < b.size()){
                grid[i][j + 1] = min(grid[i][j + 1], grid[i][j] + 1);
            }
            if(i < a.size() && j < b.size()){
                grid[i + 1][j + 1] = min(grid[i + 1][j + 1], grid[i][j] + (a[i] == b[j] ? 0 : 1));
            }
        }
    }
    cout << grid[a.size()][b.size()];
}