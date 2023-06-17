#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> movies(n); // sorted by end time, start time
    for(int i = 0; i < n; i++){
        cin >> movies[i].second >> movies[i].first;
    }
    sort(movies.begin(), movies.end());
    int ans = 0;
    multiset<int> members;
    while(k--) members.insert(0);
    auto it = movies.begin();
    while(it != movies.end()){
        if(*(members.begin()) <= (*it).second){
            auto low = members.upper_bound((*it).second);
            low--;
            members.erase(low);
            members.insert((*it).first);
            ans++;
        }
        it++;
    }
    cout << ans;
}