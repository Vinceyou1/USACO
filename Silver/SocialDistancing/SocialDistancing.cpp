#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    int n, m; cin >> n >> m;
    vector<ll> a_intervals(m);
    vector<ll> b_intervals(m);
    for(int i = 0; i < m; i++){
        cin >> a_intervals[i] >> b_intervals[i];
    }
    sort(a_intervals.begin(), a_intervals.end());
    sort(b_intervals.begin(), b_intervals.end());
    ll high = 1e18 / n;
    ll low = 0;
    while(high - low > 0){
        // cout << "here";
        ll mid = (high + low + 1) / 2;
        ll curr_pos = a_intervals[0];
        int interval_index = 0;
        bool possible = true;
        for(int i = 1; i < n; i++){
            curr_pos += mid;
            while(interval_index < m && b_intervals[interval_index] < curr_pos) {interval_index++;}
            if(interval_index == m){
                possible = false; break;
            }
            curr_pos = max(curr_pos, a_intervals[interval_index]);
        }
        if(possible){
            low = mid;
        } else high = mid -1;
    }
    cout << low;
}