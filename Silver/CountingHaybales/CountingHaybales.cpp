#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<int> haybales(n);
    while(n--){
        cin >> haybales[haybales.size() - n - 1];
    }
    sort(haybales.begin(), haybales.end());

    while(q--){
        int a, b;
        cin >> a >> b;
        auto it_low = lower_bound(haybales.begin(), haybales.end(), a);
        auto it_high = upper_bound(haybales.begin(), haybales.end(), b);
        cout << it_high - it_low << "\n";
    }
}