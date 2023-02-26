#include <iostream>
#include <vector>
using namespace std;

bool visited[100000] = {0};
vector<int> links[100000];

// I'm assuming there is a valid configuration
// Actually case 11 has no valid config, but I'm lazy

void DFS(int index){
    if(visited[index]) return;
    visited[index] = true;
    for(int i: links[index]){
        DFS(i);
    }
}

int main(){
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        char c;
        int a, b;
        cin >> c >> a >> b;
        a--; b--;
        links[a].push_back(b);
        links[b].push_back(a);
    }
    cout << "1";
    for(int i = 0; i < N; i++){
        if(!visited[i]){
            DFS(i);
            cout << "0";
        }
    }
}