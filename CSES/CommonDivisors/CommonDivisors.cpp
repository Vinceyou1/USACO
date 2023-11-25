#include <bits/stdc++.h>
using namespace std;

int factors[1000001];

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    
    int n; cin >> n;
    vector<int> nums(n);
    for(auto &i: nums) cin >> i;
    for(int i = 0; i < n; ++i){
        int upper = (int) sqrt(nums[i]);
        for(int f = 1; f <= upper; ++f){
            if(nums[i] % f == 0){
                factors[f]++;
                if(f != nums[i] / f) factors[nums[i] / f]++;
            }
        }
    }
    for(int i = 1000000; i >= 1; --i){
        if(factors[i] >= 2) {
            cout << i;
            return 0;
        }
    }
}