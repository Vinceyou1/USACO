#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int Q;
    cin >> Q;
    map<ll, ll> array;
    while(Q--){
        int n;
        cin >> n;
        if(n){
            ll k;
            cin >> k;
            cout << array[k] << endl;
        } else {
            ll k, v;
            cin >> k >> v;
            array[k] = v;
        }
    }
    return 0;
}