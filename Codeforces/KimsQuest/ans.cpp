#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main(){
    int n; cin >> n;
    vector<bool> odd(n); // true if odd
    for(int i = 0; i < n; i++){
        int num; cin >> num;
        odd[i] = num % 2;
    }
    int e_pre = 0;
    int o_pre = 0;
    int ee_pre = 0;
    int eo_pre = 0;
    int oe_pre = 0;
    int oo_pre = 0;
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        bool o = odd[i];
        if(o){
            // updating ans, since odd can end any odd double chain
            ans += eo_pre;
            ans %= MOD;
            ans += oe_pre;
            ans %= MOD;

            // transform two pre_s into different ones by adding o
            int temp = eo_pre;
            // eo_pre += ee_pre; eo_pre %= MOD;
            eo_pre += oe_pre; oe_pre %= MOD;
            // oo_pre += oo_pre; oo_pre %= MOD;
            oo_pre += temp; oo_pre %= MOD;

            oo_pre += o_pre;
            oo_pre %= MOD;
            eo_pre += e_pre;
            eo_pre %= MOD;
            ++o_pre;
        } else {
            // updating ans, since even can end any even double chain
            ans += ee_pre;
            ans %= MOD;
            ans += oo_pre;
            ans %= MOD;

            // transform two pre_s into different ones by adding o
            int temp = oe_pre;
            oe_pre += oo_pre; oo_pre %= MOD;
            // oe_pre += eo_pre; oe_pre %= MOD;
            ee_pre += ee_pre; ee_pre %= MOD;
            // ee_pre += temp; ee_pre %= MOD;

            ee_pre += e_pre; ee_pre %= MOD;
            oe_pre += o_pre; oe_pre %= MOD;
            ++e_pre;
        }
    }
    cout << ans;    
}