#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k; cin >> n >> k;
    vector<int> cows(n);
    for(int i = 0; i < n; i++){
        cows[i] = i;
    }
    vector<set<int>> visited(n);
    for(int i = 0; i < n; i++){
        visited[i].insert(i);
    }
    while(k--){
        int a, b; cin >> a >> b;
        a--; b--;
        visited[cows[a]].insert(b);
        visited[cows[b]].insert(a);
        int temp = cows[a];
        cows[a] = cows[b];
        cows[b] = temp;
    }

    vector<int> ans(n);
    for(int i = 0; i < n; i++){
        if(ans[i]) continue;
        vector<int> component;
        int index = i;
        do {
            component.push_back(index);
            index = cows[index];
        } while (index != i);
        set<int> distinct;
        for(int i: component){
            for(int j: visited[i]){
                distinct.insert(j);
            }
        }
        for(int i: component){
            ans[i] = distinct.size();
        }
    }
    for(int i: ans){
        cout << i << endl;
    }
}