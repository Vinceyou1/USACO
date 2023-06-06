#include <bits/stdc++.h>
using namespace std;

bool check_map(map<string, int> &m){
    for(auto i: m){
        if(i.second > 1) return false;
    }
    return true;
}

int main(){
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);
    int length;
    cin >> length;
    string s;
    cin >> s;

    for(int k = 1; k <= length; k++){
        map<string, int> m;
        for(int i = 0; i <= length - k; i++){
            m[s.substr(i, k)]++;
        }
        if(check_map(m)){ cout << k; break;}
    }
    return 0;
}