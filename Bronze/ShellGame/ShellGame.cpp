#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> guesses(3);
    while(n--){
        int a, b, g;
        cin >> a >> b >> g;
        a--; b--; g--;
        swap(guesses[a], guesses[b]);
        guesses[g]++;
    }
    cout << max(max(guesses[0], guesses[1]), guesses[2]);
}