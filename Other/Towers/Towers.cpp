#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    multiset<int> bases;
    while(n--){
        int s;
        cin >> s;
        auto it = bases.upper_bound(s);
        if(it != bases.end()){
            bases.erase(it);
        }
        bases.insert(s);
    }
    cout << bases.size();
}