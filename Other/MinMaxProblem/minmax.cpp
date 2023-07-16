#include <bits/stdc++.h>
using namespace std;

int arrays[300000][8];

int main(){
    int n, m; cin >> n >> m;
    int max_a = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arrays[i][j];
            max_a = max(max_a, arrays[i][j]);
        }
    }
    int left = -1; int right = max_a + 1;
    int array1 = 1, array2 = 1;
    while(right - left > 0){
        int mid = (right + left + 1) / 2;
        vector<pair<int, int>> bitmasks;
        map<int, bool> mask_found;
        for(int i = 0; i < n; i++){
            int mask = 0;
            for(int j = 0; j < m; j++){
                if(arrays[i][j] >= mid){
                    mask += 1 << j;
                }
            }
            if(!mask_found.count(mask)){
                bitmasks.push_back({mask, i});
                mask_found[mask] = true;
            }
        }
        bool found = false;
        for(int i = 0; i < bitmasks.size(); i++){
            if(found) break;
            for(auto j = i; j < bitmasks.size(); j++){
                if((bitmasks[i].first | bitmasks[j].first) == (1 << m) - 1) {
                    found = true;
                    array1 = bitmasks[i].second; array2 = bitmasks[j].second;
                    break;
                }
            }
        }
        if(found){
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    cout << array1 + 1 << " " << array2 + 1;
}