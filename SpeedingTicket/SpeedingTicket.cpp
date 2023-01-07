#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main(){
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> limit;
    vector<pair<int, int>> speed;
    for (int c = 0; c < n; c++){
        int a, b;
        cin >> a >> b;
        limit.push_back(make_pair(a, b));
    }
    int result = 0;
    int index = 0;
    int dlimit = 0;
    int dspeed = 0;
    for (int c = 0; c < m; c++){
        int a, b;
        cin >> a >> b;
        dspeed+=a;
        while(dlimit < dspeed){
            result = max(result, b-limit.at(index).second);
            if(dlimit+limit.at(index).first <= dspeed){
                dlimit+=limit.at(index).first;
                index++;
            } else break;
        }
    }
    cout << result;

    return 0;
}