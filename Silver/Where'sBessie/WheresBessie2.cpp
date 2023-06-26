#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 20;
char image[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

struct PCL{
    int x1, y1, x2, y2;
};

bool PCL_in_PCL(PCL a, PCL b){
    return (
        (b.x1 <= a.x1 && a.x1 <= b.x2) && 
        (b.x1 <= a.x2 && a.x2 <= b.x2) && 
        (b.y1 <= a.y1 && a.y1 <= b.y2) && 
        (b.y1 <= a.y2 && a.y2 <= b.y2));
}

void floodfill(int x, int y, char c, PCL a){
    if(x < a.x1 || x > a.x2 || y < a.y1 || y > a.y2) return;
    if(visited[x][y]) return;
    if(image[x][y] != c) return;
    visited[x][y] = true;
    floodfill(x+1, y, c, a);
    floodfill(x-1, y, c, a);
    floodfill(x, y+1, c, a);
    floodfill(x, y-1, c, a);
}

bool is_PCL(PCL a){
    for(int x = a.x1; x <= a.x2; x++){
        for(int y = a.y1; y <= a.y2; y++){
            visited[x][y] = false;
        }
    }
    char c1 = '.';
    char c2 = '.';
    int c1_count = 1;
    int c2_count = 1;
    for(int x = a.x1; x <= a.x2; x++){
        for(int y = a.y1; y <= a.y2; y++){
            if(!visited[x][y]){
                floodfill(x, y, image[x][y], a);
                char c = image[x][y];
                if(c1 == '.') c1 = c;
                else if (c2 == '.') c2 = c;
                else{
                    if(c == c1) c1_count++;
                    else if(c == c2) c2_count++;
                    else return false;
                }
            }
        }
    }
    return (c1 != '.' && c2 != '.') && ((c1_count > 1 && c2_count == 1) || (c2_count > 1 && c1_count == 1));
}

int main(){
    freopen("where.in", "r", stdin);
    freopen("where.out", "w", stdout);
    int n;
    cin >> n;
    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            cin >> image[x][y];
        }
    }
    vector<PCL> pcls;
    for(int x_l = 0; x_l < n; x_l++){
        for(int x_r = x_l; x_r < n; x_r++){
            for(int y_l = 0; y_l < n; y_l++){
                for(int y_r = y_l; y_r < n; y_r++){
                    PCL a;
                    a.x1 = x_l; a.y1 = y_l; a.x2 = x_r; a.y2 = y_r;
                    if(is_PCL(a)) pcls.push_back(a);
                }
            }
        }
    }
    int count = 0;
    for(int i = 0; i < pcls.size(); i++){
        PCL a = pcls[i];
        bool in = false;
        for(int j = 0; j < pcls.size(); j++){
            if(i == j) continue;
            if(PCL_in_PCL(pcls[i], pcls[j])){
                in = true; break;
            }
        }
        if(!in) {
            count++;
        }
    }
    cout << count << endl;
}