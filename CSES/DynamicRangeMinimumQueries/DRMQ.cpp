#include <bits/stdc++.h>
using namespace std;

void set_val(vector<int> &segtree, int value, int index)
{
    index += segtree.size() / 2;
    segtree[index] = value;
    for(; index > 1; index /= 2){
        segtree[index / 2] = min(segtree[index], segtree[index ^ 1]);
    }
}

int main() 
{
    int n, q; cin >> n >> q;
    vector<int> segtree(2*n);
    for(int i = 0; i < n; ++i){
        int val; cin >> val;
        set_val(segtree, val, i);
    }
    while(q--){
        int type; cin >> type;
        if(type == 1){
            int k, u; cin >> k >> u;
            set_val(segtree, u, k - 1);
        } else {
            int a, b; cin >> a >> b;
            int ans = INT32_MAX;
            a += n - 1; b += n - 1;
            while(a <= b){
                if(a % 2 == 1){
                    ans = min(ans, segtree[a]);
                    ++a;
                }
                if(b % 2 == 0){
                    ans = min(ans, segtree[b]);
                    --b;
                }
                a /= 2;
                b /= 2;
            }
            cout << ans << endl;
        }
    }
}