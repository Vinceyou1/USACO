#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100000;
char cows[MAX_N];
bool visited[MAX_N];
vector<int> connections[MAX_N];

void clear(){
    for(auto &i: visited){i = false;}
}

bool search(int a, int b, char p, bool curr){
    if(visited[a]) return false;
    visited[a] = true;
    if(cows[a] == p) curr = true;
    if(a == b) return curr;
    for(int i: connections[a]){
        if(search(i, b, p, curr)) return true;
    }
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
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        connections[a].push_back(b);
        connections[b].push_back(a);
    }
    for(int i = 0; i < m; i++){
        clear();
        int a, b; char p;
        cin >> a >> b >> p;
        a--; b--;
        cout << search(a, b, p, false);
    }
}