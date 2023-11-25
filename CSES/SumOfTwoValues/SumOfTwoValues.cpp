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
    int left = 0;
    int right = values.size() - 1;
    while(right > left){
        while(values[right].first + values[left].first > x && right > left + 1) right--;
        if(values[right].first + values[left].first == x){
            cout << values[left].second << " " << values[right].second; return 0;
        }
        left++;
    }
    cout << "IMPOSSIBLE";
    return 0;
}