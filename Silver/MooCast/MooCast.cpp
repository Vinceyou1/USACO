#include <bits/stdc++.h>
using namespace std;

int distance(int x1, int x2, int y1, int y2){
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int DFS(int i, vector<tuple<int, int, int>> &cows, vector<bool> &reached){
    int search = 0;
    reached[i] = true;
    for(int c = 0; c < cows.size(); c++){
        if(i == c || reached[c]) continue;
        if(distance(get<0>(cows[i]), get<0>(cows[c]), get<1>(cows[i]), get<1>(cows[c])) <= get<2>(cows[i]) * get<2>(cows[i])){
            search++;
            search += DFS(c, cows, reached);
        }
    }
    return search;
}

int main(){
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    int n;
    cin >> n;
    vector<tuple<int, int, int>> cows;
    while(n--){
        int x, y, p;
        cin >> x >> y >> p;
        cows.push_back({x, y, p});
    }
    vector<int> possible;
    for(int i = 0; i < cows.size(); i++){
        vector<bool> reached(cows.size());
        possible.push_back(DFS(i, cows, reached));
    }
    int ans = 0;
    for(auto i: possible){
        ans = max(i, ans);
    }
    cout << ans + 1;
}