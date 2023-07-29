#include <bits/stdc++.h>
using namespace std;

int assign(int index, bool assignment, vector<vector<int>> &accused, vector<vector<int>> &vouch, vector<bool> &is_alien, vector<bool> &assigned){
    bool possible = true;
    is_alien[index] = assignment;
    assigned[index] = true;
    int parasites = assignment;
    for(int i: accused[index]){
        if(!possible) break;
        if(!assigned[i]){
            int ans = assign(i, !is_alien[index], accused, vouch, is_alien, assigned);
            if(ans == -1) possible = false;
            else parasites += ans;
        } else {
            possible = is_alien[index] != is_alien[i];
        }
    }
    for(int i: vouch[index]){
        if(!possible) break;
        if(!assigned[i]){
            int ans = assign(i, is_alien[index], accused, vouch, is_alien, assigned);
            if(ans == -1) possible = false;
            else parasites += ans;
        } else {
            possible = is_alien[index] == is_alien[i];
        }
    }
    if(!possible) return -1;
    else return parasites;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n, q; cin >> n >> q;
        vector<vector<int>> accused(n);
        vector<vector<int>> vouch(n);
        while(q--){
            int type, i, j; cin >> type >> i >> j;
            i--; j--;
            if(type == 1) {
                accused[i].push_back(j);
                accused[j].push_back(i);
            }
            else {
                vouch[i].push_back(j);
                vouch[j].push_back(i);
            }
        }
        vector<bool> is_alien(n);
        vector<bool> assigned(n);
        vector<bool> is_alien2(n);
        vector<bool> assigned2(n);
        bool possible = true;
        int parasites = 0;
        for(int i = 0; i < n; i++){
            if(!possible) break;
            if(!assigned[i]){
                int ans1 = assign(i, false, accused, vouch, is_alien, assigned);
                int ans2 = assign(i, true, accused, vouch, is_alien2, assigned2);
                int m = max(ans1, ans2);
                if(m == -1) possible = false;
                else parasites += m;
            }
        }
        if(!possible) cout << -1;
        else cout << parasites;
        cout << endl;
    }
}