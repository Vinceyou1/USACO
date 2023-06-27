#include <bits/stdc++.h>
using namespace std;

list<int> connections[100000];
int outdegree[100000];
vector<pair<int, int>> outdegree_edges;

bool assign_edges(int index){
    while(connections[index].size() > 0){
        int i = connections[index].front();
        if(outdegree[index] % 2 == 1){
            outdegree[index]++;
            outdegree_edges.push_back({i+1, index+1});
        } else {outdegree[i]++; outdegree_edges.push_back({index+1, i+1});}
        connections[index].pop_front();
        connections[i].erase(find(connections[i].begin(), connections[i].end(), index));
    }
    return outdegree[index] % 2 == 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    if(m % 2 == 1) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    int edges[100000];
    while(m--){
        int a, b;
        cin >> a >> b;
        a--; b--;
        connections[a].push_back(b);
        connections[b].push_back(a);
        edges[a]++; edges[b]++;
    }
    set<pair<int, int>> edges_index;
    for(int i = 0; i < n; i++){
        edges_index.insert({edges[i], i});
    }

    while(edges_index.size() > 0){
        auto begin = edges_index.begin();
        if(!assign_edges((*begin).second)){
            cout << "IMPOSSIBLE";
            return 0;
        }
        edges_index.erase(begin);
    }
    for(int i = 0; i < outdegree_edges.size(); i++){
        cout << outdegree_edges[i].first << ' ' << outdegree_edges[i].second << '\n';
    }
}