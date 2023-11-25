#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll calc_modulus(ll a, ll power, int modulo){
    if(power == 0){
        return 1;
    }
    if(power == 1){
        return a % modulo;
    }
    ll half = calc_modulus(a, power / 2, modulo);
    ll ans = half*half;
    ans %= modulo;
    if(power % 2 == 1) ans *= a;
    ans %= modulo;
    return ans;
}

int main(){
    int n; cin >> n;
    while(n--){
        ll a, b, c; cin >> a >> b >> c;
        cout << calc_modulus(a, calc_modulus(b, c, 1000000006), 1000000007) << endl;
    }
}