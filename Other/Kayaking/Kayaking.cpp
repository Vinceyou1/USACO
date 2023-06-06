#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> weights(2*n);
    for(int i = 0; i < 2*n; i++){
        cin >> weights[i];
    }
    sort(weights.begin(), weights.end());
    int ans = INT32_MAX;
    for(int i = 0; i < 2*n; i++){
        for(int j = i + 1; j < 2*n; j++){
            int instability = 0;
            for(int c = 0; c < 2*n;){
                if(c == i || c == j){
                    c++;
                    continue;
                }
                int d = c + 1;
                while(d == i || d == j){d++;}
                instability += weights.at(d) - weights.at(c);
                c = d + 1;
            }
            ans = min(ans, instability);
        }
    }
    cout << ans;
}