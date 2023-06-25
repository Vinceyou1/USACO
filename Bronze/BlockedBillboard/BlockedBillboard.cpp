#include <bits/stdc++.h>
#include <cmath>
using namespace std;

struct Rect{
    int bl_x, bl_y, tr_x, tr_y;
    int area(){
        return (tr_x - bl_x) * (tr_y - bl_y);
    }
};

int intersection(Rect a, Rect b){
    return (max(0, min(a.tr_x, b.tr_x) - max(a.bl_x, b.bl_x))) * 
        (max(0, min(a.tr_y, b.tr_y) - max(a.bl_y, b.bl_y)));
}

int main(){
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    Rect a, b, c;
    cin >> a.bl_x >> a.bl_y >> a.tr_x >> a.tr_y;
    cin >> b.bl_x >> b.bl_y >> b.tr_x >> b.tr_y;
    cin >> c.bl_x >> c.bl_y >> c.tr_x >> c.tr_y;

    cout << a.area() - intersection(a, c) + b.area() - intersection(b, c);
    return 0;
}