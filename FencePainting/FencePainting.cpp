#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);

    int a;
    int b;
    int c;
    int d;
    cin >> a >> b >> c >> d;
    
    
    int range = max(max(a,b), max(c,d)) - min(min(a, b), min(c, d));
    
    if((a<=c && c<=b) || (a<=d && d<=b)) cout << range;
    else if ((c<=a && a<=d) || (c<=b && b<=d)) cout << range;
    else cout << b-a + d-c;
    return 0;
}