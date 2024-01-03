#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> hp(n);
    for(int &i: hp) cin >> i;
    int ans = INT32_MAX;
    multiset<int, greater<int>> left; // hp + (size - 1) - index
    multiset<int, greater<int>> right; // hp + index
    vector<int> values(n);
    for(int i = 1; i < n; ++i){
        values[i] = i + hp[i];
        right.insert(values[i]);
    }
    left.insert(0);
    for(int i = 0; i < n; ++i){
        int max1 = *(right.begin());
        int max2 = *(left.begin());
        int max_val = max(hp[i], max(max1, max2));
        ans = min(ans, max_val);

        // move elements
        left.insert(hp[i] + n - 1 - i);
        if(right.size()){
            int val = hp[i + 1] + i + 1;
            right.erase(right.find(val));
        }
    }
    cout << ans;
}