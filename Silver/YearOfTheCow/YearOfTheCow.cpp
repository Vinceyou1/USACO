#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k; cin >> n >> k;
    vector<int> ancestors;
    ancestors.push_back(0);
    for(int i = 0; i < n; i++){
        int year; cin >> year;
        ancestors.push_back((year / 12) + 1); // pushback how many 12 year cycles back bessie needs to jump
    }
    sort(ancestors.begin(), ancestors.end());
    multiset<int> cycles_between; // set of the distances between all ancestor cyles
    for(int i = 1; i < ancestors.size(); i++){
        cycles_between.insert(ancestors[i] - ancestors[i - 1]);
    }
    while(cycles_between.size() > k - 1){
        cycles_between.erase(cycles_between.begin());
    }
    int ans = 0; int year = ancestors[ancestors.size() - 1];
    for(int ancestor = ancestors.size() - 1; ancestor >= 0;){
        if(year == 0) break;
        year -= 1;
        ans += 1;
        while(ancestor >= 0 && ancestors[ancestor] > year) ancestor--;
        int gap = ancestors[ancestor + 1] - ancestors[ancestor];
        auto it = cycles_between.find(gap);
        if(it != cycles_between.end()){
            year = ancestors[ancestor];
            cycles_between.erase(it);
        }
    }
    cout << ans * 12;
}