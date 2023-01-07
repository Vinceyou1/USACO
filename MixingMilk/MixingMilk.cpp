#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main(){
    pair<int, int> milk[3];
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);

    cin >> milk[0].first >> milk[0].second >> milk[1].first >> milk[1].second >> milk[2].first >> milk[2].second;
    for(int c = 0; c < 100; c++){
        int i = c % 3;
        int next = (i+1)%3;
        int pour = min(milk[i].second, milk[next].first - milk[next].second);
        milk[i].second -= pour;
        milk[next].second += pour;
    }
    cout << milk[0].second << endl << milk[1].second << endl << milk[2].second << endl;

    return 0;
}