#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;

ll calc_exponentiation(ll a, ll power){
    if(power == 1) return a; 
    if(power == 0) return 1;
    ll half = calc_exponentiation(a, power / 2);
    ll ans = (half*half) % mod;
    if(power % 2 == 1){
        ans *= a; ans %= mod;
    }
    return ans;
}

ll calc_mod_inverse(ll a){
    return calc_exponentiation(a, mod - 2);
}

int main(){
    int q; cin >> q;
    ll multiplier = 1; ll constant = 0;
    deque<pair<ll, ll>> dq; // function index, then a, b
    while(q--){
        int i; cin >> i;
        switch(i){
            case 0: {
                ll a, b;
                cin >> a >> b;
                multiplier *= a; multiplier %= mod;
                constant *= a; constant %= mod;
                constant += b; constant %= mod;
                dq.push_back({a, b});
                break;
            }
            case 1: {
                auto p = dq.front();
                dq.pop_front();
                ll inverse = calc_mod_inverse(p.first) % mod;
                multiplier *= inverse; multiplier %= mod;
                constant -= (p.second * multiplier) % mod; constant %= mod;
                break;
            }
            case 2:{
                ll x; cin >> x;
                cout << ((multiplier * x % mod + constant % mod) + mod) % mod << endl;
                break;
            }
        }
    }
}