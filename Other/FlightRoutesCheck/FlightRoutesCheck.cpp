#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> f[100000];
vector<int> b[100000];
bool visited[100000] = {0};

void visitForward(int index){
    if(visited[index]) return;
    visited[index] = true;
    for(int i: f[index]){
        visitForward(i);
    }
}

void visitBackward(int index){
    if(visited[index]) return;
    visited[index] = true;
    for(int i: b[index]){
        visitBackward(i);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        f[x].push_back(y);
        b[y].push_back(x);
    }
    visitForward(0);
    for(int i = 0; i < N; i++){
        if(!visited[i]){
            cout << "NO" << "\n" << 1 << " " << i+1;
            return 0;
        }
    }
    fill(visited, visited + N, false);
    visitBackward(0);
    for(int i = 0; i < N; i++){
        if(!visited[i]){
            cout << "NO" << "\n" << i+1 << " " << 1;
            return 0;
        }
    }
    cout << "YES";
}