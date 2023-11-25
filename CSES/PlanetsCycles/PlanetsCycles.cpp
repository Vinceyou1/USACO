#include <bits/stdc++.h>
using namespace std;

int portals[200001];
int ans[200001];
bool visited[200001];

void DFS(int i, int orig, int total, vector<int> &current){
    if(ans[i]){
        total += ans[i];
        for(int &c: current){
            ans[c] = total--;
        }
        return;
    }
    if(visited[i]){
        if(i == orig){
            for(int &c: current){
                ans[c] = total;
            }
        } else {
            int c = 0;
            for(; current[c] != i; c++){
                ans[current[c]] = total--;
            }
            for(; c < current.size(); c++){
                ans[current[c]] = total;
            }
        }
        return;
    }
    visited[i] = true;
    current.push_back(i);
    DFS(portals[i], orig, total+1, current);
}

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> portals[i];
    }
    for(int i = 1; i <=n; i++){
        vector<int> current;
        DFS(i, i, 0, current);
        cout << ans[i] << " ";
    }
    // vector<int> current;
    // DFS(1, 1, 0, current);
    // for(int i = 1; i <= n; i++){
    //     cout << ans[i];
    // }
}