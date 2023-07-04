#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n, q;
    cin >> n;
    vector<ll> orig(n+1);
    vector<ll> sorted(n+1);
    vector<ll> prefix(n+1);
    for(ll i = 1; i <= n; i++){
        cin >> orig[i];
        sorted[i] = orig[i];
    }
    sort(sorted.begin(), sorted.end());
    ll t = 0;
    for(ll i = 1; i <= n; i++){
        t += i*sorted[i];
        prefix[i] = sorted[i] + prefix[i-1];
    }
    cin >> q;
    while(q--){
        ll i, j;
        cin >> i >> j;
        ll value = orig[i];
        ll curr_index = lower_bound(sorted.begin(), sorted.end(), value) - sorted.begin();
        ll new_index = upper_bound(sorted.begin(), sorted.end(), j) - sorted.begin() - 1;
        // cout << value << " " << curr_index << " " << new_index << endl;
        ll temp = t;
        if(new_index > curr_index){
            temp -= prefix[new_index] - prefix[curr_index];
            temp -= curr_index * value;
            temp += j * new_index;
        } else if(new_index < curr_index){
            temp += prefix[curr_index - 1] - prefix[new_index];
            temp -= curr_index * value;
            temp += j * (new_index + 1);
        } else if(new_index == curr_index){
            temp += curr_index * (j - value);
        }
        cout << temp << endl;
    }
}