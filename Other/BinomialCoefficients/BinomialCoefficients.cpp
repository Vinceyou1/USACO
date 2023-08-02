#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1000000007;

ll exp(ll a, int pow){
    if(pow == 0) return 1;
    if(pow == 1) return a % MOD;
    ll half = exp(a, pow / 2);
    ll ans = half * half % MOD;
    if(pow % 2 == 1){
        ans *= a;
        ans %= MOD;
    }
    return ans;
}

int main(){
    vector<ll> factorials(1000001);
    factorials[0] = 1;
    for(int i = 1; i < factorials.size(); i++){
        factorials[i] = (i * factorials[i - 1]) % MOD;
    }

    vector<ll> factorial_mod_inverse(1000001);
    for(int i = 1; i < factorial_mod_inverse.size(); i++){
        factorial_mod_inverse[i] = exp(factorials[i], MOD - 2);
    }

    int n; cin >> n;
    while(n--){
        ll a, b; cin >> a >> b;
        if(b == 0) cout << 1;
        else if(a == b) cout << 1;
        else cout << (((factorials[a] * factorial_mod_inverse[b]) % MOD) * factorial_mod_inverse[a - b]) % MOD;
        cout << endl;
    }
}