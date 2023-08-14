#include <bits/stdc++.h>
using namespace std;

int beauty[1000][1000];
int n; 

long long solve(){
    long long ans = 0;
    for(int row = 0; row < n; row++){
        int sum1 = 0, sum2 = 0;
        for(int col = 0; col < n; col++){
            if(col % 2){
                sum1 += beauty[row][col];
            } else sum2 += beauty[row][col];
        }
        ans += max(sum1, sum2);
    }
    return ans;
}

int main() {
    cin >> n;
    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            cin >> beauty[r][c];
        }
    }

    long long ans = 0; 
    ans = solve();

    // Flip rows and cols
    for(int r = 0; r < n; r++){
        for(int c = 0; c < r; c++){
            int temp = beauty[r][c];
            beauty[r][c] = beauty[c][r];
            beauty[c][r] = temp;
        }
    }
    
    ans = max(ans, solve());
    cout << ans;
}