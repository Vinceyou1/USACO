#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n, m; cin >> n >> m;
    vector<ll> a_occurences(m + 1);
    vector<ll> b_occurences(m + 1);
    for(int i = 0; i < n; i++){
        ll a, b; cin >> a >> b;
        a_occurences[a]++; b_occurences[b]++;
    }
    vector<ll> starts(2 * m + 1);
    vector<ll> ends(2 * m + 1);
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= m; j++){
            starts[i + j] += a_occurences[i] * a_occurences[j];
            ends[i + j] += b_occurences[i] * b_occurences[j];
        }
    }
    ll curr_intervals = 0;
    for(int i = 0; i <= 2 * m; i++){
        curr_intervals += starts[i];
        cout << curr_intervals << endl;
        curr_intervals -= ends[i];
    }
}