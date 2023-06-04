#include <bits/stdc++.h>
using namespace std;

int airport[200000];
int times[200000];
vector<pair<int, pair<int, int>>> flights[200000]; 
bool visited[200000] = {0};

void DFS(int index, int time, bool f){
    if(!visited[index] || times[index] > time){
        times[index] = time;
        visited[index] = true;
        if(f) time += airport[index];
        for(auto &i: flights[index]){
            if(i.second.first != -1){
                if(i.first >= time){
                    DFS(i.second.first, i.second.second, true);
                    i.second.first = -1;
                }
            }   
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    int N, M;
    cin >> N >> M;
    fill(times, times+N, -1);
    for(int i = 0; i < M; i++){
        int c, r, d, s;
        cin >> c >> r >> d >> s;
        c--; d--;
        flights[c].push_back(make_pair(r, make_pair(d, s)));
    }
    
    for(int i = 0; i < N; i++){
        cin >> airport[i];
    }

    DFS(0, 0, false);
    for(int i = 0; i < N; i++){
        cout << times[i] << "\n";
    }
}