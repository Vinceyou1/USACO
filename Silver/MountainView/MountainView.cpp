#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
    int n;
    cin >> n;
    int visible = 0;
    vector<pair<pair<int, int>, bool>> mountains;
    while(n--){
        int x, y;
        cin >> x >> y;
        bool vis = true;
        int blocked = 0;
        for(int i = 0; i < mountains.size(); i++){
            if(abs(mountains[i].first.first - x) <= abs(mountains[i].first.second - y)) {
                if(y - mountains[i].first.second > 0){
                    if(mountains[i].second){
                        blocked++;
                        mountains[i].second = false;
                    }
                }
                else{
                    vis = false; break;
                }
            }
        }
        if(vis){
            visible++;
            visible -= blocked;
            mountains.push_back({{x, y}, true});
        }
        else{
            mountains.push_back({{x, y}, false});
        }
        
    }
    cout << visible;
}