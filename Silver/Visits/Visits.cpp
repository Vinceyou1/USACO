#include <bits/stdc++.h>
using namespace std;

pair<int, int> visits[100001]; // destination, moos
long long ans = 0;
bool visited[100001];

void visit(int i, vector<int> &list){
    if(visited[i]){
        if (list.size() == 0) return;
        int index = 0;
        while(index < list.size()){
            if(list[index] == i) break;
            ans += visits[list[index]].second;
            index++;
        }
        if(index != list.size()){ // cycle detected
            int subtract = INT32_MAX;
            while(index < list.size()){
                ans += visits[list[index]].second;
                subtract = min(subtract, visits[list[index]].second);
                index++;
            }
            ans -= subtract;
        }
    }
    else {
        list.push_back(i);
        visited[i] = true;
        visit(visits[i].first, list);
    }

}

int main(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> visits[i].first >> visits[i].second;
    }
    for(int i = 1; i <= n; i++){
        vector<int> list;
        visit(i, list);
    }
    cout << ans;
}