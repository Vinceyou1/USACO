#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    int m = INT32_MIN;
    while(n--) {
        cin >> nums[n];
        m = max(m, nums[n]);
    }
    
    long long ans = LONG_LONG_MAX / 2 + 1;
    for(long long d = ans / 2; d > 0; d /= 2){
        int count = 1;
        long long sum = 0;
        if(ans - d < m) continue;
        for(int i = 0; i < nums.size(); i++){
            if(sum + nums[i] > ans - d){
                count++;
                sum = 0;
            }
            sum += nums[i];
        }
        if(count <= k) {
            ans -= d;
        };
    }

    cout << ans;

}