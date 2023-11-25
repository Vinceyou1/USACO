#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int x, n;
    cin >> x >> n;
    set<int> lights;
    lights.insert(0);
    lights.insert(x);
    multiset<int> lengths;
    lengths.insert(x-0);
    while(n--){
        int p;
        cin >> p;
        
        auto right = lights.upper_bound(p);
        auto left = right;
        left--;

        int length = *right - *left;
        lengths.erase(lengths.find(length));
        lengths.insert(*right - p);
        lengths.insert(p - *left);
        cout << *(--lengths.end()) << " ";
        lights.insert(p);
    }
    return 0;
}