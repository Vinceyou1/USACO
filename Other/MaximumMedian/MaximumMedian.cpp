#include <bits/stdc++.h>
using namespace std;

int k;

int bin_search(vector<long long> &nums){
    int median = (nums.size()-1)/2;
    for(int d = INT32_MAX/2 + 1; d > 0; d/=2){
        long long total = 0;
        long long x = nums[median] + d;
        for(int i = median; i < nums.size(); i++){
            total += max(0LL, x - nums[i]);
        }
        if(total <= k){
            nums[median] = x;
            k -= d;
        }
    }
    return nums[median];
}

int main(){
    int n;
    cin >> n >> k;
    vector<long long> nums(n);
    while(n--){
        cin >> nums[nums.size() - n - 1];
    }
    sort(nums.begin(), nums.end());
    cout << bin_search(nums);

    return 0;
}