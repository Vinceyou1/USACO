#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);
    int n, k; cin >> n >> k;
    vector<int> trees;
    for(int i = 0; i < n; i++){
        int berries; cin >> berries;
        trees.push_back(berries);
    }
    sort(trees.begin(), trees.end());
    int max_berries = 0;
    for(int b = 1000; b >= 1; b--){
        int baskets_filled = 0;
        int i = trees.size() - 1;
        priority_queue<int> remainder;
        for(; i >= 0; i--){
            if(trees[i] < b) break; 
            baskets_filled += trees[i] / b;
            remainder.push(trees[i] % b);
        }
        baskets_filled -= k / 2;
        if(baskets_filled < 0){
            continue;
        }
        int baskets_left = k / 2 - min(k / 2, baskets_filled);
        int berries = min(k / 2, baskets_filled) * b;
        for(;;){
            if(baskets_left <= 0) break;
            if(remainder.size() == 0 && i < 0) break;
            if(i < 0 || remainder.top() > trees[i]){
                berries += remainder.top();
                remainder.pop();
            } else {
                berries += trees[i];
                i--;
            }
            baskets_left--;
        }
        max_berries = max(max_berries, berries);
    }
    cout << max_berries;
}