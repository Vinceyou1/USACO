#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> nums;

int main(){
    ll n; ll k; cin >> n >> k;
    nums.resize(n);
    for(auto &i: nums) cin >> i;
    sort(nums.begin(), nums.end());

    ll high = 1000000000;
    ll low = 0;
    while(high - low > 0){
        ll mid = (high + low) / 2; // distance
        // cout << mid << endl;
        ll min_operations = LLONG_MAX;
        // bool possible = false;
        // Do a left to right two pointers search
        ll p1 = 0; ll p2 = 0; // p2 points to the index 1 to the right 
        ll right_bound = nums[p1] + mid;
        while(p2 < n && nums[p2] <= right_bound) p2++;
        ll nums_to_the_left = 0; ll nums_to_the_right = nums.size() - p2;
        ll operations_needed = 0;
        for(ll i = p2; i < n; i++){
            operations_needed += nums[i] - right_bound;
        }
        min_operations = min(min_operations, operations_needed);
        // cout << p1 << " " << p2 << ": " << operations_needed << endl;
        while(p2 < n){
            do{
                p1++;
                nums_to_the_left++;
            } while(p1 < n && nums[p1 - 1] == nums[p1]);
            operations_needed += nums_to_the_left * (nums[p1] - nums[p1 - 1]);

            ll new_right_bound = nums[p1] + mid;
            while(p2 < n && nums[p2] <= new_right_bound) {
                operations_needed -= nums[p2] - right_bound; // previous operations added for this number
                p2++;
                nums_to_the_right -= 1;
            }
            operations_needed -= nums_to_the_right * (new_right_bound - right_bound);
            // cout << p1 << " " << p2 << ": " << operations_needed << endl;
            right_bound = new_right_bound;
            min_operations = min(min_operations, operations_needed);
        }

        // Do a right to left two pointers search
        p1 = nums.size() - 1; p2 = nums.size() - 1; // p2 points to the index 1 to the right 
        ll left_bound = nums[p2] - mid;
        while(p1 >= 0 && nums[p1] >= left_bound) p1--;
        nums_to_the_left = p1 + 1; nums_to_the_right = 0;
        operations_needed = 0;
        for(ll i = 0; i <= p1; i++){
            operations_needed += left_bound - nums[i];
        }
        min_operations = min(min_operations, operations_needed);
        // cout << p1 << " " << p2 << ": " << operations_needed << endl;
        while(p1 >= 0){
            do{
                p2--;
                nums_to_the_right++;
            } while(p2 >= 0 && nums[p2 + 1] == nums[p2]);
            operations_needed += nums_to_the_right * (nums[p2 + 1] - nums[p2]);

            ll new_left_bound = nums[p2] - mid;
            while(p1 >= 0 && nums[p1] >= new_left_bound) {
                operations_needed -= left_bound - nums[p1]; // previous operations added for this number
                p1--;
                nums_to_the_left -= 1;
            }
            operations_needed -= nums_to_the_left * (left_bound - new_left_bound);
            // cout << p1 << " " << p2 << ": " << operations_needed << endl;
            left_bound = new_left_bound;
            min_operations = min(min_operations, operations_needed);
        }

        if(min_operations <= k){
            high = mid;
        } else low = mid + 1;

    }
    cout << low;
}