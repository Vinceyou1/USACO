#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, q; cin >> n >> q;
    string coms; cin >> coms;
    set<pair<pair<int, int>, int>> visits; // stores by coord point, then time visited
    pair<int, int> point = {0, 0};
    vector<pair<int, int>> coord_after_com(n + 1);
    int time = 0;
    visits.insert({point, time});
    for(int i = 0; i < n; ++i){
        switch(coms[i]){
            case 'U':
                point.second += 2;
                break;
            case 'D':
                point.second -= 2;
                break;
            case 'R':
                point.first += 2;
                break;
            case 'L':
                point.first -= 2;
                break;
        }
        time++;
        visits.insert({point, time});
        coord_after_com[time] = point;
    }
    while(q--){
        int x, y, l, r;
        cin >> x >> y >> l >> r;
        x *= 2; y *= 2;
        bool found = false;
        auto coord = make_pair(x, y);
        if(visits.upper_bound({coord, l-1}) != visits.lower_bound({coord, 0})) found = true;
        if(visits.upper_bound({coord, n}) != visits.lower_bound({coord, r})) found = true;
        if(!found){
            auto pre_coord = coord_after_com[l - 1];
            auto final_coord = coord_after_com[r];
            auto center_coord = make_pair((final_coord.first + pre_coord.first) / 2, (final_coord.second + pre_coord.second) / 2);
            auto dif = make_pair(center_coord.first - coord.first, center_coord.second - coord.second);
            auto reflected_coord = make_pair(center_coord.first + dif.first, center_coord.second + dif.second);
            if(visits.upper_bound({reflected_coord, r}) != visits.lower_bound({reflected_coord, l})) found = true;
        }
        cout << (found ? "YES" : "NO") << endl;
    }
}