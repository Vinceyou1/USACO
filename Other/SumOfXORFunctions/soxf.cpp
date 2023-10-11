#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<long long> nums(n);
    for(long long &num: nums) cin >> num;
    const int MOD = 998244353;
    // solve this bit by bit
    long long ans = 0;
    for(int i = 0; i < 31; ++i){
        long long xor_0_count = 1;
        long long xor_0_sum = -1;
        long long xor_1_count = 0;
        long long xor_1_sum = 0;
        int cur_xor = 0;
        long long sum = 0;
        for(int num = 0; num < n; ++num){
            if(nums[num] & (1 << i)){
                cur_xor ^= 1;
            }
            if(cur_xor){
                xor_1_count++;
                xor_1_sum += num;
                sum += xor_0_count * num - xor_0_sum;
            } else {
                xor_0_count++;
                xor_0_sum += num;
                sum += xor_1_count * num - xor_1_sum;
            }
            sum %= MOD;
        }
        ans += sum * (1 << i);
        ans %= MOD;
    }


    cout << ans;
}