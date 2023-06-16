#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    set<pair<int, int>> movies; // end, start
    int a, b;
    while(n--){   
        cin >> a >> b;
        movies.insert({b, a});
    }
    auto it = movies.begin();
    int current_time = 0;
    int ans = 0;
    while(it != movies.end()){
        if((*it).second >= current_time){
            current_time = (*it).first;
            ans++;
        }
        it++;
    }
    cout << ans;
}