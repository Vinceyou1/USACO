#include <iostream>
#include <vector>
using namespace std;

vector<int> friends[200000];
bool visited[100000] = {0};
bool group[100000];
bool q = false;

void DFS(int index, bool b){
    if(visited[index]){
        if(group[index] == b) q = true;
    } else {
        visited[index] = true;
        group[index] = !b;
        for(int i: friends[index]){
            DFS(i, !b);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }
    for(int i = 0; i < N; i++){
        if(!visited[i]) DFS(i, true);
    }

    if(q) cout << "IMPOSSIBLE";
    else{
        for(int i = 0; i < N; i++){
            if(group[i]) cout << "2" << " ";
            else cout << "1" << " ";
        }
    }
}