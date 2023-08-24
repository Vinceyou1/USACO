#include <bits/stdc++.h>
using namespace std;


// Partial Solution, tle on last 3 test cases
int main(){
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    int n; cin >> n;
    vector<pair<int, int>> x_first;
    vector<pair<int, int>> y_first;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        x_first.push_back({x, y});
        y_first.push_back({y, x});
    }
    sort(x_first.begin(), x_first.end());
    sort(y_first.begin(), y_first.end());

    vector<int> prefix_y_vals(n + 1);
    vector<int> prefix_x_vals(n + 1);
    for(int i = 1; i <= n; i++){
        prefix_x_vals[i] = prefix_x_vals[i - 1] + y_first[i - 1].second;
        prefix_y_vals[i] = prefix_y_vals[i - 1] + x_first[i - 1].second;
    }

    long long ans = 0;
    for(int i = 0; i < n; i++){
        auto coord = x_first[i];
        int y_index = find(y_first.begin(), y_first.end(), make_pair(coord.second, coord.first)) - y_first.begin();
        int x_start = lower_bound(x_first.begin(), x_first.end(), make_pair(coord.first, -10000)) - x_first.begin();
        int x_end = upper_bound(x_first.begin(), x_first.end(), make_pair(coord.first, 10000)) - x_first.begin();
        int y_start = lower_bound(y_first.begin(), y_first.end(), make_pair(coord.second, -10000)) - y_first.begin();
        int y_end = upper_bound(y_first.begin(), y_first.end(), make_pair(coord.second, 10000)) - y_first.begin();

        long long abs_y_sum = (((long long) (i - x_start)) * coord.second - (prefix_y_vals[i] - prefix_y_vals[x_start])) + (prefix_y_vals[x_end] - prefix_y_vals[i + 1] - (((long long) (x_end - i - 1)) * coord.second));
        long long abs_x_sum = (((long long) (y_index - y_start)) * coord.first - (prefix_x_vals[y_index] - prefix_x_vals[y_start])) + (prefix_x_vals[y_end] - prefix_x_vals[y_index + 1] - (((long long) (y_end - y_index - 1)) * coord.first));
        ans += abs_y_sum * abs_x_sum;
        ans %= 1000000007;
    }
    cout << ans;
}