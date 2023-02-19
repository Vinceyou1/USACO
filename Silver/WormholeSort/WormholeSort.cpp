#include <bits/stdc++.h>
using namespace std;

int binSearch(vector<pair<int, pair<int, int>>> vect, int i, int l, int r){
    int mid = (l+r)/2;
    int val = vect.at(mid).first;
    if(val == i) {
        while(vect.at(mid).first == i) mid--;
        return ++mid;
    }
    else if(val > i) return binSearch(vect, i, l, mid -1);
    else return binSearch(vect, i, mid+1, r);
}

int main(){
    // freopen("wormsort.out", "w", stdout);
    int n, m; cin >> n >> m;
    vector<int> positions(n);
    for(int i = 0; i < n; i++){
        cin >> positions.at(i);
    }
    vector<pair<int, pair<int, int>>> wormholes(m);
    for(int i = 0; i < m; i++){
        int x, y, w; cin >> x >> y >> w;
        wormholes.push_back({x, {y, w}});
        wormholes.push_back({y, {x, w}});
    }
    sort(wormholes.begin(), wormholes.end());
    // Finding connected components
    int ans = -1;
    for(int i = 0; i < n; i++){
        if(positions.at(i) == i+1) continue;
        if(positions.at(i)){
            vector<int> component;
            int temp = i;
            do{
                component.push_back(positions.at(temp));
                temp = positions.at(temp)-1;
            } while(temp != i);
            component.push_back(i+1);
            int handled = 0;
            while(handled < component.size()){
                int index = binSearch(wormholes, component.at(handled), 0, wormholes.size()-1);
                int rmax = -1;
                while(wormholes.at(index).first == component.at(handled)){
                    if(wormholes.at(index).second.first == component.at((handled+1)%component.size())){
                        rmax = max(rmax, wormholes.at(index).second.second);
                        cout << "here";
                    }
                    index++;
                    if(index==wormholes.size()) break;
                }
                cout << rmax << " ";
                
                ans = max(ans, rmax);
                handled++;
            }
            for(int i: component){
                
                positions.at(i-1) = 0;
            }
        }
    }
    
    cout << ans;
}