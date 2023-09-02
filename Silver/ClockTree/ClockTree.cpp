#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("clocktree.in", "r", stdin);
    int n; cin >> n;
    vector<int> clocks(n);
    for(int &i: clocks) cin >> i;
    vector<vector<int>> corridors(n);
    for(int i = 1; i < n; i++){
        int a, b; cin >> a >> b; a--; b--;
        corridors[a].push_back(b); corridors[b].push_back(a);
    }
    queue<int> one;
    queue<int> two;
    one.push(0);
    vector<bool> visited(n);
    visited[0] = true;

    int one_mod = 0;
    int two_mod = 0;
    int one_count = 0;
    int two_count = 0;
    while(one.size() || two.size()){
        while(one.size()){
            int t = one.front();
            one.pop();
            one_mod += clocks[t];
            one_mod %= 12;
            one_count++;
            for(int i: corridors[t]){
                if(!visited[i]){
                    visited[i] = true;
                    two.push(i);
                }
            }
        }
        while(two.size()){
            int t = two.front();
            two.pop();
            two_mod += clocks[t];
            two_mod %= 12;
            two_count++;
            for(int i: corridors[t]){
                if(!visited[i]){
                    visited[i] = true;
                    one.push(i);
                }
            }
        }
    }

    freopen("clocktree.out", "w", stdout);
    if(one_mod == two_mod) cout << n;
    else if((one_mod + 1) % 12 == two_mod) cout << two_count;
    else if((two_mod + 1) % 12 == one_mod) cout << one_count;
    else cout << 0;

}