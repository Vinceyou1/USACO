#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> nums(n);
        for(auto &i: nums) cin >> i;
        for(int size = 1; size <= n; size++){
            int max_gcd = 0;
            for(int i = 0; i < n - size + 1; i++){
                if(size != 1){
                    nums[i] = gcd(nums[i], nums[i + 1]);
                }
                max_gcd = max(max_gcd, nums[i]);
            }
            cout << max_gcd << " ";
        }
        cout << endl;
    }
}