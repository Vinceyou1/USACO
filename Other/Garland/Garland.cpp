#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<char> garland(n);
    for(char &c: garland){
        cin >> c;
    }
    int q; cin >> q;
    while(q--){
        int changes;
        char fav;
        cin >> changes >> fav;
        int p1 = 0; int p2 = 0;
        int fav_in_interval = 0;
        int max_koyomity = 0;
        while(p2 <= n){
            while(p2 - p1 <= changes + fav_in_interval && p2 <= n){
                // cout << "p2: " << p2;
                max_koyomity = max(max_koyomity, p2 - p1);
                fav_in_interval+=garland[p2] == fav;
                p2++;
            }
            while(p2 - p1 > changes + fav_in_interval){
                // cout << "p1: " << p1;
                fav_in_interval -= garland[p1] == fav;
                p1++;
            }
        }
        cout << max_koyomity << "\n";
    }
}