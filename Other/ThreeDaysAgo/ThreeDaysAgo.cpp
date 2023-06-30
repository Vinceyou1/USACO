#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;

    int bits = 0;
    map<int, long long> states;
    states[bits]++;
    for(int i = 0; i < s.size(); i++){
        int c = s.at(i) - '0';
        bits ^= 1 << c;
        states[bits]++;
    }
    long long ans = 0;
    for(auto ele: states){
        ans += (ele.second) * (ele.second - 1) / 2; 
    }
    cout << ans;
}