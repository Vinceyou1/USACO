#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 21;
bool match[MAX_N][MAX_N];
int ans[1 << MAX_N][MAX_N];
const int MOD = 1000000007;
int n;

int possibilites(int s, int index){
    if(index == -1){
        if(s == 0){
            return 1;
        } else return 0;
    }
    if(ans[s][index]) return ((ans[s][index] == -1) ? 0 : ans[s][index]);
    for(int i = 0; i < n; i++) {
        if(((1 << i) & s) && match[index][i]){
            ans[s][index] += possibilites(s^(1<<i), index-1);
            ans[s][index] %= MOD;
        }
    }
    if(!ans[s][index]) ans[s][index] = -1;
    return ((ans[s][index] == -1) ? 0 : ans[s][index]);
}

int main() {
    cin >> n;
    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            cin >> match[r][c];
        }
    }

    cout << possibilites((1 << n) - 1, n - 1);
}