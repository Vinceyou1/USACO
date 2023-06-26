#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> connections[5000];

int suggested(int k, int v, int prev, int min_rel){
    int val = 0;
    if(min_rel >= k) val++;
    for(auto p: connections[v]){
        if(p.first == prev) continue;
        val += suggested(k, p.first, v, min(min_rel, p.second));
    }
    return val;
}

int main(){
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    n--;
    while(n--){
        int p, q, r;
        cin >> p >> q >> r;
        p--; q--;
        connections[p].push_back({q, r});
        connections[q].push_back({p, r});
    }
    while(q--){
        int k, v;
        cin >> k >> v;
        v--;
        cout << suggested(k, v, -1, INT32_MAX) - 1 << endl;
    }   
}