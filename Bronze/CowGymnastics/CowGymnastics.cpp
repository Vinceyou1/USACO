#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    
    int k, n;
    cin >> k >> n;
    int positions[11][21]; // indexed by session, then by cow
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= n; j++){
            int c; cin >> c;
            positions[i][c] = j;
        }
    }
    int pairs = 0;
    for(int i = 1; i <= n - 1; i++){
        for(int j = i + 1; j <= n; j++){
            bool consistent = true;
            bool i_less_j = positions[1][i] < positions[1][j];
            for(int session = 2; session <= k; session++){
                if(i_less_j != (positions[session][i] < positions[session][j])){
                    consistent = false;
                    break;
                }
            }
            if(consistent) {pairs++;}
        }
    }
    cout << pairs;
    return 0;
}