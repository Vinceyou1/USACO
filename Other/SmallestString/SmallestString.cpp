#include <bits/stdc++.h>
using namespace std;

bool smaller(string a, string b){
    int i1 = 0;
    int i2 = 0;
    while (true){
        if(a.at(i1) < b.at(i2)){
            return true;
        } else if(a.at(i1) > b.at(i2)) return false;
        if(i1 == a.length() - 1 && i2 == b.length() - 1) break;
        i1++; i2++;
        i1 %= a.length();
        i2 %= b.length();
    }
    return false;
}

int main(){
    int n; cin >> n;
    vector<string> strings(n);
    for(auto &i: strings) cin >> i;
    sort(strings.begin(), strings.end(), smaller);
    for(auto i: strings) cout << i;
}