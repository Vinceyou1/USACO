#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> routes(n);
    while(m--){
        int a, b; cin >> a >> b;
        a--; b--;
        routes[a].push_back(b);
        routes[b].push_back(a);
    }

    vector<bool> visited(n);
    queue<int> bfs; bfs.push(0);
    vector<int> number(n);
    number[0] = 1;
    visited[0] = true;
    while(bfs.size()) {
        int t = bfs.front();
        bfs.pop();
        for(int i: routes[t]){
            if(!visited[i]){
                visited[i] = true;
                number[i] = number[t] + 1;
                bfs.push(i);
            }
        }
        if(number[n - 1]) break;
    }

    if(number[n - 1]){
        cout << number[n - 1] << endl;
        vector<int> path;
        int steps = number[n - 1] - 1;
        int index = n - 1;
        while(steps) {
            path.push_back(index);
            for(int i: routes[index]){
                if(number[i] == steps){
                    index = i;
                    break;
                }
            }
            steps--;
        }
        path.push_back(0);
        for(int i = path.size() - 1; i >= 0; i--) {
            cout << path[i] + 1 << " ";
        }
    }
    else cout << "IMPOSSIBLE";
}