#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    
    int n; cin >> n;
    vector<int> nums(n);
    for(auto &i: nums) cin >> i;
    int curr_max_factor = 1;
    set<int> factors;
    for(int i = 0; i < n; i++){
        for(int f = 1; f*f <= nums[i]; f++){
            if(nums[i] % f == 0){
                if(!factors.insert(f).second) curr_max_factor = max(f, curr_max_factor);
                if(f*f != nums[i]){
                    if(!factors.insert(nums[i] / f).second) curr_max_factor = max(nums[i] / f, curr_max_factor);
                }
            }
        }
    }
    cout << curr_max_factor;
}