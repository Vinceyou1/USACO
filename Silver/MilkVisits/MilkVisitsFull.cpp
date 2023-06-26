#include <bits/stdc++.h>
using namespace std;

bool components[100000];
vector<int> connections[100000];
char cows[100000];
int component[100000];

void DFS(int index, int current_component, int prev_index, char prev){
    if(cows[index] == prev){
        component[index] = current_component;
    } else {
        while(components[current_component]){
            current_component++;
        }
        components[current_component] = true;
        component[index] = current_component;
    }
    for(int i: connections[index]){
        if(i == prev_index) continue;
        DFS(i, current_component, index, cows[index]);
    }
}

bool eval(int a, int b, char c){
    if(component[a] != component[b]) return true;
    if(cows[a] == c) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> cows[i];
    }
    for(int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        connections[x].push_back(y);
        connections[y].push_back(x);
    }
    DFS(0, 0, -1, '.');
    while(m--){
        int a, b; char c;
        cin >> a >> b >> c;
        a--; b--;
        cout << eval(a, b, c);
    }
}