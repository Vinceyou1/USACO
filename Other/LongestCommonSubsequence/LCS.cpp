#include <bits/stdc++.h>
using namespace std;


int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int>> grid(text1.size(), vector<int>(text2.size()));
    for(int x = 0; x < text1.size(); x++){
        for(int y = 0; y < text2.size(); y++){
            if(text1[x] == text2[y]){
                grid[x][y] = 1;
                if(x > 0 && y > 0) grid[x][y] += grid[x - 1][y - 1];
            }
            if(x > 0){
                grid[x][y] = max(grid[x][y], grid[x - 1][y]);
            }
            if(y > 0){
                grid[x][y] = max(grid[x][y], grid[x][y - 1]);
            }
        }
    }
    return grid[text1.size() - 1][text2.size() - 1];
}

int main(){
    string a, b; cin >> a >> b;
    cout << longestCommonSubsequence(a, b);
}