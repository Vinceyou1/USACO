#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> primes(k);
    for(auto &i: primes){
        cin >> i;
    }
    ll ans = 0;
    for(ll b = 1; b < 1 << k; b++){
        ll temp = 0;
        ll prime_count = 0;
        ll multiple = 1;
        for(int i = 0; i < k; i++){
            if(b & (1LL << i)){
                if(n / primes[i] < multiple) {prime_count = 0; break;}
                else{
                    multiple *= primes[i];
                    prime_count++;
                }
            }
        }
        if(prime_count == 0) continue;
        temp = n / multiple;
        if(prime_count % 2 == 1) ans += temp;
        else { ans -= temp;}
    }
    cout << ans;
}