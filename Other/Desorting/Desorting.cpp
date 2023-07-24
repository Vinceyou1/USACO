#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> nums(n);
        for(int &i: nums){
            cin >> i;
        }
        int min_operations = INT32_MAX;
        for(int i = 0; i < n - 1; i++){
            if(nums[i + 1] < nums[i]) min_operations = -1;
            min_operations = min(min_operations, (nums[i + 1] - nums[i]) / 2 + 1);
        }
        cout << max(min_operations, 0) << endl;
    }
}