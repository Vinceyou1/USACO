#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> nums(n);
    for(int &i: nums) cin >> i;
    map<int, int> height_to_pos;
    for(int i = 0; i < n; i++){
        height_to_pos[nums[i]] = i + 1;
    }
    long long ans = 0;
    set<int> positions;
    for(int height = n; height > 0; height--){
        auto it = positions.insert(height_to_pos[height]).first;
        if(positions.size() == 1) continue;
        if(it == positions.begin()){
            it++;
            ans += (*it) - height_to_pos[height] + 1; 
        } else if(it == --(positions.end())){
            it--;
            ans += height_to_pos[height] - (*it) + 1;
        } else {
            it++;
            ans += (*it) - height_to_pos[height] + 1; 
            it--; it--;
            ans += height_to_pos[height] - (*it) + 1;
        }
    }
    cout << ans;
}