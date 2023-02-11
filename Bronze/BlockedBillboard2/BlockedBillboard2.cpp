#include <bits/stdc++.h>
using namespace std;

struct Rectangle{
    int x1, y1, x2, y2;
    int area(){
        return (x2-x1)*(y2-y1);
    }
};



int main(){
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    Rectangle rect1;
    Rectangle rect2;
    cin >> rect1.x1 >> rect1.y1 >> rect1.x2 >> rect1.y2;
    cin >> rect2.x1 >> rect2.y1 >> rect2.x2 >> rect2.y2;

    int xoverlap = min(rect1.x2, rect2.x2) - max(rect1.x1, rect2.x1);
    int yoverlap = min(rect1.y2, rect2.y2) - max(rect1.y1, rect2.y1);

    if(xoverlap == rect1.x2-rect1.x1){
        rect1.y2 -= yoverlap;
    }
    if(yoverlap == rect1.y2-rect1.y1){
        rect1.x2 -= xoverlap;
    }

    cout << rect1.area();
    return 0;
}