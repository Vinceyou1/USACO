#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> connections[5000]; // index, relevance
int relevance[5000][5000];

void find_relevances(int origin, int index, int current){
    if(relevance[origin][index] != 0) return;
    relevance[origin][index] = current;
    for(int i = 0; i < connections[index].size(); i++){
        auto p = connections[index][i];
        find_relevances(origin, p.first, min(p.second, current));
    }
}
// vector<pair<int, int>> solve(int index){
//     vector<pair<int, int>> r;
//     for(auto p: connections[index]){
//         r.push_back(p.second);
//         auto v = solve(p.first);
//         for(auto p2: v){
//             r.push_back(p2.second);
//         }
//     }
//     sort(r.begin(), r.end());
// }

int bin_search(int v, int k){
    int left = 0; int right = 5000;
    while(right - left > 0){
        int mid = (right + left) / 2;
        if(relevance[v][mid] >= k) right = mid;
        else left = mid + 1;
    }
    return left;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("10.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i < n; i++){
        int p, q, r;
        cin >> p >> q >> r;
        p--; q--;
        connections[q].push_back({p, r});
        connections[p].push_back({q, r});
    }
    for(int i = 0; i < n; i++){
        find_relevances(i, i, INT32_MAX);
    }
    for(int i = 0; i < 5000; i++){
        sort(relevance[i], relevance[i] + 5000);
    }
    while(q--){
        int k, v;
        cin >> k >> v;
        v--;
        int index = bin_search(v, k);
        cout << 5000 - index - 1 << endl;
    }
}