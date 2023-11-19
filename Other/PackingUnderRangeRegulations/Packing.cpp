#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<pair<int, int>> ranges(n);
        for(int i = 0; i < n; ++i){
            cin >> ranges[i].first >> ranges[i].second;
        }
        sort(ranges.begin(), ranges.end());
        int box = ranges[0].first;
        int range_index = 0;
        priority_queue<int, vector<int>, greater<int>> current_ranges; // only includes the right bound, since left bound doesn't matter
        bool ans = true;
        while(range_index < ranges.size() || current_ranges.size()){
            while(range_index < ranges.size() && ranges[range_index].first <= box){
                current_ranges.push(ranges[range_index].second);
                range_index++;
            }

            int top = current_ranges.top();
            current_ranges.pop();
            if(top < box){
                ans = false;
                break;
            }
            box += 1;
            if(current_ranges.size() == 0 && range_index < ranges.size()){
                box = max(box, ranges[range_index].first);
            }
        }
        cout << (ans ? "Yes" : "No") << "\n";
    }
}