#include <bits/stdc++.h>
using namespace std;

char ice_cream[1000][1000];
bool accounted[1000][1000];
int n;

pair<int, int> floodfill(int x, int y){
    if(x >= n || y >= n || x < 0 || y < 0) return(make_pair(0, 0));
    if(accounted[x][y]) return(make_pair(0, 0));
    accounted[x][y] = true;
    int perim = 4;
    if(x != 0 && ice_cream[x-1][y] == '#') perim-=2;
    if(y != 0 && ice_cream[x][y-1] == '#') perim-=2;
    auto p1 = floodfill(x+1, y);
    auto p2 = floodfill(x, y+1);
    auto p3 = floodfill(x-1, y);
    auto p4 = floodfill(x, y-1);
    return make_pair(1+p1.first+p2.first+p3.first+p4.first, perim+p1.second+p2.second+p3.second+p4.second);
}

int main(){
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    cin >> n;
    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            char c; cin >> c;
            ice_cream[x][y] = c;
            if(ice_cream[x][y] == '.') accounted[x][y] = true;
        }
    }
    multiset<pair<int, int>> areas; // areas, then perimeters
    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            if(accounted[x][y]) continue;
            areas.insert(floodfill(x, y));
        }
    }
    auto it = --(areas.end());
    auto area = (*it).first;
    auto min_perim = (*it).second;
    while(area == (*it).first){
        if(it == areas.begin()) break;
        min_perim = min(min_perim, (*it).second);
        it--;
    }
    if(it == areas.begin() && (*it).first == area) min_perim = min(min_perim, (*areas.begin()).second);
    cout << area << " " << min_perim;
}