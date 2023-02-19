#include <iostream>
using namespace std;

int prefixes[1001][1001] = {0};

int main(){
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++){
        for(int c = 1; c <= n; c++){
            char ch; cin >> ch;
            prefixes[c][i] = prefixes[c-1][i] + prefixes[c][i-1] - prefixes[c-1][i-1];
            if(ch=='*') prefixes[c][i]++;
        }
    }
    for(int i = 0; i < q; i++){
        // a and c are y for some reason
        int a, b, c, d; cin >> a >> b >> c >> d;
        cout << prefixes[d][c] - prefixes[d][a-1] - prefixes[b-1][c] + prefixes[b-1][a-1] << endl;
    }
}