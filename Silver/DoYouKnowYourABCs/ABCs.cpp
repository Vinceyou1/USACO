#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        // A, B, C, A + B, B + C, C + A, A + B + C
        int n; cin >> n;
        vector<int> nums(7);
        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }
        sort(nums.begin(), nums.end());
        set<tuple<int, int, int>> s; // A, B, C
        do {
            vector<int> temp;
            for(int i: nums) temp.push_back(i);
            if(!temp[0] && !temp[1] && !temp[2]){
                if(temp[3] + temp[4] + temp[5] == temp[6] * 2){
                    temp[0] = temp[6] - temp[4];
                } else {
                    continue;
                }
            }
            // Now guaranteed to have at least one of A, B, or C
            vector<bool> assigned = {temp[0] == 0, temp[1] == 0, temp[2] == 0};
            while(!temp[0] || !temp[1] || !temp[2]){
                // cout << endl;
                // cout << temp[0] << " " << temp[1] << " " << temp[2] << endl;
                // cout << assigned[0] << " " << assigned[1] << " " << assigned[2] << endl;
                if(temp[0] && !temp[1] && temp[3]){
                    temp[1] = temp[3] - temp[0];
                    assigned[1] = true;
                }
                if(temp[0] && !temp[2] && temp[5]){
                    temp[2] = temp[5] - temp[0];
                    assigned[2] = true;
                }
                if(temp[1] && !temp[0] && temp[3]){
                    temp[0] = temp[3] - temp[1];
                    assigned[0] = true;
                }
                if(temp[1] && !temp[2] && temp[4]){
                    temp[2] = temp[4] - temp[1];
                    assigned[2] = true;
                }
                if(temp[2] && !temp[0] && temp[5]){
                    temp[0] = temp[5] - temp[2];
                    assigned[0] = true;
                }
                if(temp[2] && !temp[1] && temp[4]){
                    temp[1] = temp[4] - temp[2];
                    assigned[1] = true;
                }
                if(temp[0] && temp[1] && !temp[2] && temp[6]){
                    temp[2] = temp[6] - temp[0] - temp[1];
                    assigned[2] = true;
                }
                if(temp[1] && temp[2] && !temp[0] && temp[6]){
                    temp[0] = temp[6] - temp[1] - temp[2];
                    assigned[0] = true;
                }
                if(temp[0] && temp[2] && !temp[1] && temp[6]){
                    temp[1] = temp[6] - temp[0] - temp[2];
                    assigned[1] = true;
                }
                if(temp[0] == 0 && assigned[0] ||
                    temp[1] == 0 && assigned[1] ||
                    temp[2] == 0 && assigned[2]) break;
            }
            if(!temp[3]) temp[3] = temp[0] + temp[1];
            if(!temp[4]) temp[4] = temp[1] + temp[2];
            if(!temp[5]) temp[5] = temp[0] + temp[2];
            if(!temp[6]) temp[6] = temp[0] + temp[1] + temp[2];
            // check for validity
            // A, B, C, A + B, B + C, C + A, A + B + C
            if(temp[0] > 0 && temp[1] > 0 && temp[2] > 0 && temp[0] + temp[1] == temp[3] && temp[1] + temp[2] == temp[4] && 
                temp[0] + temp[2] == temp[5] && temp[0] + temp[1] + temp[2] == temp[6]){    
                    vector<int> ans = {temp[0], temp[1], temp[2]};
                    sort(ans.begin(), ans.end());
                    s.insert({ans[0], ans[1], ans[2]});
                }
        } while(next_permutation(nums.begin(), nums.end()));
        cout << s.size() << endl;
    }
}