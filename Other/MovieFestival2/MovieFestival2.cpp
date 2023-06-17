#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    multiset<pair<int, int>> movies; // sorted by end time, start time
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        movies.insert({b, a});
    }
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