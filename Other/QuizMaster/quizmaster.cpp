#include <bits/stdc++.h>
using namespace std;

vector<int> factors(int num, int m){
    vector<int> ans;
    for(int i = 1; i <= sqrt(num) && i <= m; i++){
        if(num % i == 0){
            ans.push_back(i);
            if(num / i <= m){ans.push_back(num / i);}
        }
    }
    return ans;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<int> nums(n);
        for(auto &i: nums){
            cin >> i;
        }
        sort(nums.begin(), nums.end());
        int p1 = 0; int p2 = 0; 
        map<int, int> factor_map; // factor -> occurences
        int min_diff = INT32_MAX;
        while(p1 <= n - 1){
            if(factor_map.size() < m){
                if(p2 == n) break;
                for(int i: factors(nums[p2], m)){
                    factor_map[i]++;
                }
                p2++;
            } else {
                min_diff = min(min_diff, nums[p2 - 1] - nums[p1]);
                if(p1 == p2) break;
                for(int i: factors(nums[p1], m)){
                    factor_map[i]--;
                    if(factor_map[i] == 0){
                        factor_map.erase(i);
                    }
                } p1++;
            }
        }
        if(min_diff == INT32_MAX){
            cout << -1;
        } else cout << min_diff;
        cout << "\n";
    }
}