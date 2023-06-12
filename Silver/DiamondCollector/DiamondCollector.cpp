#include <bits/stdc++.h>
using namespace std;

vector<int> diamonds;
int k;

// int max_case(int lower_bound, int upper_bound){
//     int left = lower_bound;
//     int right = lower_bound;
//     int ans = 0;
//     while(right < upper_bound){
//         if(diamonds[right] - diamonds[left] <= k){
//             ans = max(right - left + 1, ans);
//             right++;
//         }
//         else{left++;}
//     }
//     return ans;
// }

int solve(){
    vector<int> left_maxes(diamonds.size() + 1);
    vector<int> right_maxes(diamonds.size() + 1);
    int left_max_left = 0;
    int left_max_right = 0;
    int left = 0;
    int m = 0;
    left_maxes[0] = 0;
    right_maxes[diamonds.size()] = 0;
    for(int i = 0; i < diamonds.size(); i++){
        while(diamonds[i] - diamonds[left] > k) left++;
        if(i - left + 1 > m){
            left_max_left = left;
            left_max_right = i;
            m = i - left + 1;
        }
        left_maxes[i + 1] = left_max_right - left_max_left + 1;
    }

    int right_max_right = diamonds.size() - 1;
    int right_max_left = diamonds.size() - 1;
    int right = diamonds.size() - 1;
    m = 0;

    for(int i = diamonds.size() - 1; i >= 0; i--){
        while(diamonds[right] - diamonds[i] > k) right--;
        if(right - i + 1 > m){
            right_max_right = right;
            right_max_left = i;
            m = right - i + 1;
        }
        right_maxes[i] = right_max_right - right_max_left + 1;
    }
    int ans = 0;
    for(int i = 0; i <= diamonds.size(); i++){
        ans = max(ans, left_maxes[i] + right_maxes[i]);
    }
    return ans;

    // int ans = 0;
    // for(int i = 0; i <= diamonds.size(); i++){
    //     ans = max(ans, max_case(0, i) + max_case(i, diamonds.size()));
    // }
    // return ans;
}

int main(){
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int n;
    cin >> n >> k;
    while(n--){
        int s;
        cin >> s;
        diamonds.push_back(s);
    }
    sort(diamonds.begin(), diamonds.end());
    cout << solve();
}