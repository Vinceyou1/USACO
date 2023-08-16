#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("cereal.in", "r", stdin);
    freopen("cereal.out", "w", stdout);
    int n, m; cin >> n >> m;
    vector<pair<int, int>> cows(n);
    vector<vector<int>> cereal_to_cows(m + 1);
    for(int i = 0; i < n; i++){
        cin >> cows[i].first >> cows[i].second;
        cereal_to_cows[cows[i].first].push_back(i);
        cereal_to_cows[cows[i].second].push_back(i);
    }

    // Calculate initial state
    vector<int> cereal(n);
    vector<bool> taken(m + 1);
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(!taken[cows[i].first]){
            cereal[i] = cows[i].first;
            taken[cows[i].first] = true;
        } else if(!taken[cows[i].second]){
            cereal[i] = cows[i].second;
            taken[cows[i].second] = true;
        }
        if(cereal[i]) ans++;
    }
    cout << ans << endl;
    for(int i = 0; i < n - 1; i++){
        if(cereal[i]) ans--;
        queue<pair<int, int>> s;
        if(cereal[i]){
            for(int cow: cereal_to_cows[cereal[i]]) {
                if(cow <= i) continue; // might need to optimize with an array of current indices?
                if(cereal[i] == cows[cow].first || !cereal[cow]){
                    s.push({cow, cereal[i]});
                    break;
                }
            }
            cereal[i] = 0;
        } 
        while(s.size()){
            auto cur = s.front();
            s.pop();
            int old_cereal = cereal[cur.first];
            ans += (old_cereal == 0);
            cereal[cur.first] = cur.second;
            for(int cow: cereal_to_cows[old_cereal]) {
                if(cow <= cur.first) continue; // might need to optimize with an array of current indices?
                if(old_cereal == cows[cow].first || !cereal[cow]){
                    s.push({cow, old_cereal});
                    break;
                }
            }
        }
        cout << ans << endl;
    }
}