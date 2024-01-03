#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string s; cin >> s;
    vector<int> bessie(6);
    ll ans = 0;
    for(int i = 0; i < s.size(); ++i){
        bessie[0]++;
        char c = s.at(i);
        switch(c){
            case 'b':
                bessie[1] += bessie[0];
                bessie[0] = 0;
                break;
            case 'e':
                bessie[2] += bessie[1];
                bessie[1] = 0; 
                ans += bessie[5] * (s.size() - i);
                bessie[0] += bessie[5];
                bessie[5] = 0;
                break;
            case 's':
                bessie[4] += bessie[3];
                bessie[3] = 0;
                bessie[3] += bessie[2];
                bessie[2] = 0;
                break;
            case 'i':
                bessie[5] += bessie[4];
                bessie[4] = 0;
                break; 
        }
    }
    cout << ans;
}