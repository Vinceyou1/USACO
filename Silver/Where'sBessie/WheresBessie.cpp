#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 20;
char grid[MAX_N][MAX_N];
int evaluated[MAX_N][MAX_N][MAX_N][MAX_N];
int n;

void DFS(char previous, int x, int y, int x1, int y1, int x2, int y2, bool (&temp_eval)[MAX_N][MAX_N]){ // components, colors
    if(x < x1 || x > x2 || y < y1 || y > y2) return;
    if(temp_eval[x][y]) return;
    if(grid[x][y] != previous) return;
    temp_eval[x][y] = true;
    previous = grid[x][y];
    DFS(previous, x-1, y, x1, y1, x2, y2, temp_eval);
    DFS(previous, x, y-1, x1, y1, x2, y2, temp_eval);
    DFS(previous, x+1, y, x1, y1, x2, y2, temp_eval);
    DFS(previous, x, y+1, x1, y1, x2, y2, temp_eval);
}

bool PCL(int x1, int y1, int x2, int y2){
    bool temp_eval[MAX_N][MAX_N];
    for(auto &i: temp_eval){
        for(auto &j: i) j = false;
    }
    int c1 = -1;
    int c2 = -1;
    int c1_count = 1;
    int c2_count = 1;
    for(int x = x1; x <= x2; x++){
        for(int y = y1; y <= y2; y++){
            if(temp_eval[x][y]) continue;
            DFS(grid[x][y], x, y, x1, y1, x2, y2, temp_eval);
            int index = grid[x][y] - 'A';
            if(index != c1 && index != c2){
                if(c1 == -1) c1 = index;
                else if(c2 == -1) c2 = index;
                else return false;
            }
            else {
                if(index == c1) c1_count++;
                if(index == c2) c2_count++;
            }
        }
    }
    if(c1 == -1 || c2 == -1) return false; 
    if((c1_count == 1 && c2_count > 1) || (c1_count > 1 && c2_count == 1)) return true;
    return false;
}

int split(int x1, int y1, int x2, int y2){
    cout << 0;
    if(x1 > x2 || y1 > y2) return 0;
    if(evaluated[x1][y1][x2][y2]) return 0;
    evaluated[x1][y1][x2][y2] = 1;
    if(PCL(x1, y1, x2, y2)){
        // cout << x1 << y1 << x2 << y2 << endl;
        int points = 1;
        for(int x3 = x1; x3 <= x2; x3++){
            for(int x4 = x3; x4 <= x2; x4++){
                for(int y3 = y1; y3 <= y2; y3++){
                    for(int y4 = y3; y4 <= y2; y4++){
                        if(evaluated[x3][y3][x4][y4] == 2){
                            points--;
                        }
                        evaluated[x3][y3][x4][y4] = 1;
                    }
                }   
            }
        }
        evaluated[x1][y1][x2][y2] = 2;
        // cout << points << endl;
        return points;
    }
    return split(x1+1, y1, x2, y2) + split(x1, y1+1, x2, y2) + split(x1, y1, x2-1, y2) + split(x1, y2, x2, y2-1);
}

int main(){
    // freopen("where.in", "r", stdin);
    // freopen("where.out", "w", stdout);
    cin >> n;
    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            cin >> grid[x][y];
        }
    }
    cout << split(0, 0, n-1, n-1);
    // cout << PCL(2, 0, 3, 3);
}