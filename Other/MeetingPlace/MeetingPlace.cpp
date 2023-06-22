#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<pair<long double, long double>> friends(n);
    for(int i = 0; i < n; i++){
        cin >> friends[i].first;
    }
    for(int i = 0; i < n; i++){
        cin >> friends[i].second;
    }
    // sort(friends.begin(), friends.end());

    long double right = DBL_MAX;
    long double left = 0;
    while(right - left > 1e-6){
        long double mid = (right + left) / 2;
        long double low = -DBL_MAX;
        long double high = DBL_MAX;
        for(int i = 0; i < friends.size(); i++){
            low = max(low, friends[i].first - friends[i].second * mid);
            high = min(high, friends[i].first + friends[i].second * mid);
        }
        if(low <= high){
            right = mid;
        } else left = mid;
    }
    cout << std::setprecision (12) << right;
}