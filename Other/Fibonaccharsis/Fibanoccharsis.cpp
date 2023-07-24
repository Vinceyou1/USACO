#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    // doesn't actually need to be this long
    vector<ll> fibonacci = {0, 1};
    for(int i = 2; i < 200000; i++){
        fibonacci.push_back(fibonacci[i - 1] + fibonacci[i - 2]);
    }
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        if(k > 200000) cout << 0 << endl;
        else {
            ll num1_multiple = fibonacci[k - 2];
            ll num2_multiple = fibonacci[k - 1];
            ll num2 = n / num2_multiple;
            ll ans = 0;
            while(num2){
                ll leftover = n - num2 * num2_multiple;
                if(leftover / num1_multiple > num2) break;
                if(leftover % num1_multiple == 0) {
                    ans++;
                }
                num2--;
            }
            cout << ans << endl;
        }
    }
}