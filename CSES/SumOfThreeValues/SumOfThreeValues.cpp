#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> values;
    for(int i = 1; i <=n; i++){
        int c;
        cin >> c;
        values.push_back({c, i});
    }
    sort(values.begin(), values.end());
    
    for(int i = 0; i < n; i++){
        int left = 0;
        int right = values.size() - 1;
        if(left==i) left++;
        if(right == i) right--;
        while(right > left){
            while(values[right].first + values[left].first + values[i].first > x && right > left + 1) {
                if(--right == i) --right;
            }
            if(values[right].first + values[left].first + values[i].first == x && right != left){
                cout << values[left].second << " " << values[right].second << " " << values[i].second; return 0;
            }
            if(++left==i) left++;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}