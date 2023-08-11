#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> position(n + 1);
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            position[x] = i;
        }
        int l = (n + 1) / 2, r = (n + 2) / 2;
        while (l > 0 && (l == r || (position[l] < position[l + 1] && position[r - 1] < position[r]))) {
            l--; r++;
        }
        cout << (n - (r - l) + 1) / 2 << '\n';
    }
}