#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k; cin >> n >> k;
    vector<int> nums(n);
    for(auto &i: nums) cin >> i;
    int low = 0; int high = n;
    while(high - low > 0){
        int mid = (high + low + 1) / 2;
        vector<int> prefix(n + 1);
        vector<int> min_prefix(n + 1);
        for(int i = 1; i <= n; i++){
            prefix[i] = prefix[i - 1];
            prefix[i] += nums[i - 1] >= mid ? 1 : -1;
            min_prefix[i] = min(min_prefix[i - 1], prefix[i]);
        }
        bool possible = false;
        for(int i = k; i <= n; i++){
            if(prefix[i] - min_prefix[i - k] > 0){
                possible = true;
                break;
            }
        }
        if(possible){
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    cout << low;
}