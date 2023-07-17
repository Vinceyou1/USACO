#include <bits/stdc++.h>
using namespace std;
int n; 


vector<int> connections[100000];

vector<int> path;

bool one_to_n(int index, int prev){
    if(index == n - 1){
        path.push_back(index);
        return(true);
    }
    for(int i: connections[index]){
        if(i == prev) continue;
        if(one_to_n(i, index)){
            path.push_back(index);
            return true;
        }
    }
    return false;
}

int count_spaces(int index, int prev, int path_end){
    int ans = 1;
    for(int i: connections[index]){
        if(i == prev || i == path_end) continue;
        ans += count_spaces(i, index, path_end);
    }
    return ans;
}

int main(){
    cin >> n;
    for(int i = 1; i < n; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        connections[a].push_back(b);
        connections[b].push_back(a);
    }
    one_to_n(0, -1);
    bool fennec_turn = (path.size() % 2 == 0 ? true : false);
    int fennec_spaces = count_spaces(0, -1, path[path.size() / 2 - 1]);
    int snuke_spaces = count_spaces(n - 1, -1, path[path.size() / 2]);
    bool fennec_win;
    if(!fennec_turn){
        snuke_spaces--;
    }
    fennec_win = fennec_spaces > snuke_spaces;
    cout << (fennec_win ? "Fennec" : "Snuke");
}