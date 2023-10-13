#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> nums(n);
        for(int &i: nums) cin >> i;
        int high = 1000000000;
        int low = 0;
        while(low < high){
            int mid = (high + low + 1) / 2;
            bool possible = false;
            // want to get index i = mid
            for(int i = 0; i < n - 1; ++i){
                int front_index = i;
                // front_index should be last index we modify
                while(front_index < n){
                    if(nums[front_index] >= mid - (front_index - i)) break;
                    front_index++; 
                }
                if(front_index == n) break;
                long long sum = 0;
                for(int j = front_index; j >= i; --j){
                    int needed_value = mid - (j - i);
                    sum += max(0, needed_value - nums[j]);
                }
                if(sum <= k){
                    possible = true;
                    break;
                }
            }
            if(possible){
                low = mid;
            } else high = mid - 1;
        }
        cout << max(low, nums[n - 1]) << endl;
    }
}