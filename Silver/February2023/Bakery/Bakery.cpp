#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--){
        int n, t_c, t_m; cin >> n >> t_c >> t_m;
        vector<pair<pair<long long, long long>, long long>> friends;
        for(int i = 0; i < n; ++i){
            int a, b, c; cin >> a >> b >> c;
            friends.push_back({{a, b}, c});
        }

        long long low = 0; long long high = t_c + t_m - 2;
        while(low < high){
            long long mid = (low + high) / 2;
            
            // let x time to bake cookies
            // d is the sum of x & y
            long long d = t_c + t_m - mid;
            long long x_low_bound = max(1LL, t_c - mid);
            long long x_high_bound = min((long long)(t_c), d - 1);
            bool cond = true;

            for(long long i = 0; i < n; ++i){
                long long a = friends[i].first.first;
                long long b = friends[i].first.second;
                long long c = friends[i].second;
                
                // a * x + b(d - x) <= c
                // (a-b)x <= c - bd
                int x_coeff = a - b;
                long long right_val = c - b * d;
                if(x_coeff == 0){
                    if(right_val < 0) cond = false;
                } else if(x_coeff > 0){
                    x_high_bound = min(x_high_bound, right_val / x_coeff);
                } else {
                    x_low_bound = max(x_low_bound, (-right_val - x_coeff - 1) / -x_coeff);
                }
            }

            if(cond && x_low_bound <= x_high_bound) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        cout << low << endl;
    }
}