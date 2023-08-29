#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> s; // contains the negative of index's component if index is repr, its parent otherwise
    DSU(int n) { s = vector<int> (n, -1); }

    int repr(int x){
        if(s[x] < 0) return x;
        s[x] = repr(s[x]);
        return s[x];
    }

    int size(int x){
        x = repr(x);
        return -s[x];
    }

    int connected(int a, int b){
        a = repr(a); b = repr(b);
        return a == b;
    }

    void unite(int a, int b){
        a = repr(a); b = repr(b);
        if(a == b) return;
        if(-s[a] > -s[b]) swap(a, b);
        s[b] += s[a];
        s[a] = b;
    }
};

int main(){
    freopen("mootube.in", "r", stdin);
    int n, q; cin >> n >> q;
    vector<tuple<int, int, int>> connections; // relevance, then a, b
    for(int i = 1; i < n; i++){
        int p, q, r; cin >> p >> q >> r;
        connections.push_back({r, p - 1, q - 1});
    }

    DSU dsu(n);

    vector<tuple<int, int, int>> queries;
    vector<int> ans(q);
    for(int i = 0; i < q; i++){
        int k, v; cin >> k >> v; v--;
        queries.push_back({k, v, i});
    }

    sort(connections.begin(), connections.end(), greater<tuple<int, int, int>>());
    sort(queries.begin(), queries.end(), greater<tuple<int, int, int>>());

    int connection_index = 0;
    for(q = 0; q < queries.size(); q++){
        int k = get<0>(queries[q]);
        while(connection_index < n && get<0>(connections[connection_index]) >= k){
            dsu.unite(get<1>(connections[connection_index]), get<2>(connections[connection_index]));
            connection_index++;
        }
        ans[get<2>(queries[q])] = dsu.size(get<1>(queries[q])) - 1;
    }
    freopen("mootube.out", "w", stdout);
    for(int i: ans){
        cout << i << endl;
    }
}