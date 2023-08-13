#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 25;
bool reached[MAX_N][MAX_N][19683];
pair<char, pair<int, int>> grid[MAX_N][MAX_N];
int powers_of_3[10];
unordered_set<int> boards;
int n;

bool win(int b){
    int board[3][3];
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++) {
            board[i][j] = b%3;
            b /= 3;
        }
    }
    for (int r=0; r<3; r++) {
        if (board[r][0] == 1 && board[r][1] == 2 && board[r][2] == 2) return true;
        if (board[r][0] == 2 && board[r][1] == 2 && board[r][2] == 1) return true;
    }
    for (int c=0; c<3; c++) {
        if (board[0][c] == 1 && board[1][c] == 2 && board[2][c] == 2) return true;
        if (board[0][c] == 2 && board[1][c] == 2 && board[2][c] == 1) return true;
    }
    if (board[0][0] == 1 && board[1][1] == 2 && board[2][2] == 2) return true;
    if (board[0][0] == 2 && board[1][1] == 2 && board[2][2] == 1) return true;
    if (board[2][0] == 1 && board[1][1] == 2 && board[0][2] == 2) return true;
    if (board[2][0] == 2 && board[1][1] == 2 && board[0][2] == 1) return true;
    return false;
}

void fill(int x, int y, int b){
    if(grid[x][y].first == '#') return;
    if(reached[x][y][b]) return;
    reached[x][y][b] = true;
    if(grid[x][y].first == 'M' || grid[x][y].first == 'O'){
        int index = grid[x][y].second.first * 3 + grid[x][y].second.second;
        if((b / powers_of_3[index]) % 3 == 0){
            b += (grid[x][y].first == 'M' ? 1 : 2) * powers_of_3[index];
            if(!reached[x][y][b] && win(b)) {
                boards.insert(b);
                return;
            }
            reached[x][y][b] = true;
        }
    }
    fill(x + 1, y, b);
    fill(x - 1, y, b);
    fill(x, y + 1, b);
    fill(x, y - 1, b);
}

int main(){
    powers_of_3[0] = 1;
    for(int i = 1; i < 10; i++){
        powers_of_3[i] = 3 * powers_of_3[i - 1];
    }
    cin >> n;
    int x, y;
    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            char a, b, d; cin >> a >> b >> d;
            grid[r][c] = {a, {0, 0}};
            if(a == 'O' || a == 'M'){
                grid[r][c].second.first = b - '1';
                grid[r][c].second.second = d - '1';
            } else if(a == 'B'){
                x = r; y = c; 
            }
        }
    }
    fill(x, y, 0);
    cout << boards.size();
}