#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
using ll = long long;

ll calc_mod_exponent(ll num, ll power){
    if(power == 1) return num % MOD;
    if(power == 0) return 1;
    ll half = calc_mod_exponent(num, power / 2);
    ll ans = half * half % MOD;
    if(power % 2 == 1){
        ans *= num;
        ans %= MOD;
    }
    return ans;
}


int main(){
    int n; cin >> n;
    vector<pair<ll, ll>> factors;
    ll num = 1;
    while(n--){
        ll prime, power; cin >> prime >> power;
        factors.push_back({prime, power});
        num *= calc_mod_exponent(prime, power);
        num %= MOD;
    }
    // cout << num << endl << endl;
    // Solve for num, total, and product
    ll num_divisors = 1;
    ll product = 1;
    ll product_divisors = 1;
    ll sum = 1;
    ll sqrt = 1;
    for(auto p: factors){
        ll factor = calc_mod_exponent(p.first, p.second);
        // cout << factor << endl;
        ll sum_multiple = (factor * p.first - 1) % MOD * calc_mod_exponent(p.first - 1, MOD - 2) % MOD;
        sum *= sum_multiple;
        sum %= MOD;
        num_divisors *= p.second + 1;
        num_divisors %= MOD;
        product = calc_mod_exponent(product, p.second + 1) *
            calc_mod_exponent(calc_mod_exponent(p.first, (p.second * (p.second + 1) / 2)), product_divisors) % MOD;
        product_divisors *= p.second + 1;
        product_divisors %= MOD - 1;
        sqrt *= calc_mod_exponent(p.first, p.second / 2);
        sqrt %= MOD;
    }
    // cout << num << endl;
    cout << num_divisors << " " << sum << " " << product;
}
//* (product_divisors % 2 == 1 ? sqrt : 1))