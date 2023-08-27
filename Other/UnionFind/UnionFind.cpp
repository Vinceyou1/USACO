#include <iostream>
#include <vector>
using namespace std;

int component[200005];
vector<int> component_elems[200005];

int main(){
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        component[i] = i;
        component_elems[i].push_back(i);
    }
    while(q--){
        int t, u, v; cin >> t >> u >> v;
        if(!t){
            int c1 = component[u];
            int c2 = component[v];
            if(c1 == c2) continue;
            if(component_elems[c1].size() >= component_elems[c2].size()){
                for(int i: component_elems[c2]){
                    component_elems[c1].push_back(i);
                    component[i] = c1;
                }
            } else {
                for(int i: component_elems[c1]){
                    component_elems[c2].push_back(i);
                    component[i] = c2;
                }
            }
        } else {
            cout << (component[u] == component[v]) << endl;
        }
    }
}