#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, q; cin >> n >> q;
    vector<int> fence(n);
    for(int &i: fence) {
        char c; cin >> c;
        i = c - 'A';
    }

    vector<vector<int>> prefix(n + 2, vector<int>(26)); // prefix array of the number of each character
    for(int i = 1; i <= n; i++){
        auto v = prefix[i - 1];
        v[fence[i - 1]]++;
        prefix[i] = v;
    };

    // process the amount to paint from left to right and in reverse
    vector<int> left(n);
    vector<int> right(n);
    vector<int> last_occurrence(26, -1);
    int amt = 0;
    for(int i = 0; i < n; i++){
        int color = fence[i];
        if(last_occurrence[color] != -1) {
            int i2 = last_occurrence[color];
            // if the color has occurred before, check to see if there are lighter colors in between
            bool found = false;
            for(int lighter = color - 1; lighter >= 0; lighter--){
                if(prefix[i + 1][lighter] - prefix[i2 + 1][lighter]){
                    found = true;
                    break;
                }
            }
            if(found){
                amt++;
            }
        } else {
            amt++;
        }
        last_occurrence[color] = i;
        left[i] = amt;
    }

    fill(last_occurrence.begin(), last_occurrence.end(), -1);
    amt = 0;
    for(int i = n - 1; i >= 0; i--){
        int color = fence[i];
        if(last_occurrence[color] != -1) {
            int i2 = last_occurrence[color];
            // if the color has occurred before, check to see if there are lighter colors in between
            bool found = false;
            for(int lighter = color - 1; lighter >= 0; lighter--){
                if(prefix[i2 + 1][lighter] - prefix[i + 1][lighter]){
                    found = true;
                    break;
                }
            }
            if(found){
                amt++;
            }
        } else {
            amt++;
        }
        last_occurrence[color] = i;
        right[i] = amt;
    }

    while(q--){
        int a, b; cin >> a >> b;
        a--; b--;
        int ans = 0;
        if(a > 0){
            ans += left[a - 1];
        }
        if(b < n - 1){
            ans += right[b + 1];
        }
        cout << ans << endl;
    }
}