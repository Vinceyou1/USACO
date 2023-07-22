#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);
    int n, k, b; cin >> n >> k >> b;
    vector<int> signals(n + 1);
    while(b--){
        int x; cin >> x;
        signals[x] = 1;
    }
    for(int i = 1; i < signals.size(); i++){
        signals[i] += signals[i - 1];
    }
    int ans = INT32_MAX;
    for(int i = k; i <= n; i++){
        ans = min(ans, signals[i] - signals[i - k]);
    }
    cout << ans;
}