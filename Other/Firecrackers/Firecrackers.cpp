#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, m, a, b; cin >> n >> m >> a >> b;
        int firework_time = abs(b - a) - 1;
        int total_time = a < b ? b - 2 : n - b - 1;
        vector<int> fireworks(m);
        for(auto &i: fireworks) cin >> i;
        sort(fireworks.begin(), fireworks.end());
        int high = fireworks.size() - 1; int low = -1;
        while(high - low > 0){
            int mid = (high + low + 1) / 2;
            bool possible = true;
            if(mid + 1 > firework_time){
                possible = false;
            } else {
                for(int temp = mid; temp >= 0; temp--){
                    if(fireworks[temp] > total_time - (mid - temp)){
                        possible = false; break;
                    }                    
                }
            }
            if(possible){
                low = mid;
            } else high = mid - 1;
        }
        cout << low + 1 << endl;
    }
}