#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200000;
unordered_set<int> no_vertex[MAX_N];
vector<int> component_sizes;
set<int> unvisited;


void DFS(int index){
    unvisited.erase(index);
    component_sizes[component_sizes.size() - 1]++;

    auto it = unvisited.begin();
    while(it != unvisited.end()){
        if(no_vertex[index].count(*it)){
            it++;
            continue;
        }
        int val = *it;
        DFS(val);
        it = unvisited.upper_bound(val);
    }
}

int main(){
    int n, m; cin >> n >> m;
    while(m--){
        int a, b; cin >> a >> b;
        a--; b--;
        no_vertex[a].insert(b);
        no_vertex[b].insert(a);
    }
    for(int i = 0; i < n; i++){
        unvisited.insert(i);
    }

    for(int i = 0; i < n; i++){
        if(unvisited.count(i)){
            component_sizes.push_back(0);
            DFS(i);
        }
    }
    sort(component_sizes.begin(), component_sizes.end());
    cout << component_sizes.size() << endl;
    for(int i: component_sizes){
        cout << i << " ";
    }
}