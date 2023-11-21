#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    if(a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<pair<int, int>> departments(n);
        for(int i = 0; i < n; ++i){
            cin >> departments[i].first >> departments[i].second;
        }

        sort(departments.begin(), departments.end(), cmp);
        int max_before_b = -1;
        int ans = INT32_MAX;
        multiset<int> ending_b;
        for(int i = 0; i < n; ++i){
            ending_b.insert(departments[i].second);
        }

        for(int i = 0; i < n; ++i){
            ending_b.erase(ending_b.find(departments[i].second));
            int a = departments[i].first;
            int b = max_before_b;
            auto lower = ending_b.upper_bound(a);
            if(lower != ending_b.end()){
                if(abs(a - b) > abs(a - *lower)) b = max(max_before_b, *lower);
            }
            if(lower != ending_b.begin()){
                lower--;
                if(abs(a - b) > abs(a - *lower)) b = max(max_before_b, *lower);
            }
            if(b != -1) ans = min(ans, abs(a - b));
            max_before_b = max(max_before_b, departments[i].second);
        }
        cout << ans << endl;
    }
}