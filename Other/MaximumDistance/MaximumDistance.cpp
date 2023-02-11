#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> coords;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        coords.push_back(make_pair(x, 0));
    }
    for (int i = 0; i < n; i++){
        int y;
        cin >> y;
        coords[i].second = y;
    }

    int result = 0;
    for(int i = 0; i < n; i++){
        for(int c = i+1; c < n; c++){
            result = max(result, (int) (pow(coords[c].first-coords[i].first, 2) + pow(coords[c].second-coords[i].second, 2)));
        }
    }
    cout << result;

    return 0;   
}