#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int modulo = 1000000007;

ll calc_modulus(ll a, int power){
    if(power == 0){
        return 1;
    }
    if(power == 1){
        return a % modulo;
    }
    ll half = calc_modulus(a, power / 2);
    ll ans = half*half;
    ans %= modulo;
    if(power % 2 == 1) ans *= a;
    ans %= modulo;
    return ans;
}

int main(){
    int n; cin >> n;
    while(n--){
        ll a, b; cin >> a >> b;
        cout << calc_modulus(a, b) << endl;
    }
}