#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        map<int, int> num_to_position;
        for(int i = 0; i < n; i++){
            int num; cin >> num;
            num_to_position[num] = i;
        }
        long long total = 0;
        int l = num_to_position[0];
        int r = l;
        for(int mex = 1; mex < n; mex++){
            int mex_pos = num_to_position[mex];
            if(l <= mex_pos && mex_pos <= r) continue;
            while(mex_pos < l){
                int max_valid_right = min(n - 1, l + mex * 2 - 1);
                total += max(0, max_valid_right - r + 1);
                l--;
            }
            while(mex_pos > r){
                int max_valid_left = max(0, r - mex * 2 + 1);
                total += max(0, l - max_valid_left + 1);
                r++;
            }
        }
        // 1 additional for the whole array
        cout << total + 1 << endl;
    }
}