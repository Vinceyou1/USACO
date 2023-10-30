#include <bits/stdc++.h>
using namespace std;

struct Friend{
    int x, y, orig_index;
    bool swapped;
    bool operator<(const Friend &b){ return x < b.x; }
};

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<Friend> friends;
        for(int i = 0; i < n; ++i){
            int h, w; cin >> h >> w;
            Friend a; a.x = h; a.y = w; a.swapped = false; a.orig_index = i;
            friends.push_back(a);
            a.x = w; a.y = h;
            friends.push_back(a);
        }
        sort(friends.begin(), friends.end());
        vector<int> ans(n);
        fill(ans.begin(), ans.end(), -1);
        int min_other = INT32_MAX;
        int min_index = -1;
        int curr_min = INT32_MAX;
        int curr_min_index = -1;
        int curr_val = friends[0].x;
        for(int i = 0; i < friends.size(); ++i){
            if(friends[i].x != curr_val) {
                if(min_other > curr_min){
                    min_other = curr_min;
                    curr_min = INT32_MAX;
                    min_index = curr_min_index;
                }
            }
            if(min_other < friends[i].y){
                ans[friends[i].orig_index] = friends[min_index].orig_index;
            }
            if(curr_min > friends[i].y){
                curr_min = friends[i].y;
                curr_min_index = i;
            }
            curr_val = friends[i].x;
        }
        for(int i: ans) cout << (i == -1 ? -1 : i + 1) << " ";
        cout << endl;
    }
}