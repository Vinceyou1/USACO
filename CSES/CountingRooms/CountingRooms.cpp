#include <iostream>
using namespace std;

bool map[1000][1000];
int rooms = 0;
int n, m;
bool visited[1000][1000] = {0};

void fill(int x, int y, bool room_origin){
    if((x < 0 || y < 0 || x >= n || y >= m ) || (visited[x][y])) return;
    visited[x][y] = true;
    bool room = map[x][y];
    if(room_origin){
        if(room){
            fill(x-1, y, true);
            fill(x+1, y, true);
            fill(x, y+1, true);
            fill(x, y-1, true);
        }
    }
    else{
        if(room){
            rooms++;
            fill(x-1, y, true);
            fill(x+1, y, true);
            fill(x, y+1, true);
            fill(x, y-1, true);
        }
        else{
            fill(x-1, y, false);
            fill(x+1, y, false);
            fill(x, y+1, false);
            fill(x, y-1, false);
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int c = 0; c < m; c++){
            char ch;
            cin >> ch;
            map[i][c] = ch == '.';
        }
    }

    for(int i = 0; i < n; i++){
        for(int c = 0; c < m; c++){
            if(!visited[i][c]){
                fill(i, c, false);
            }
        }
    }
    cout << rooms;
    return 0;
}