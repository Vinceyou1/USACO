#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<unsigned int> houses(n);
    for(unsigned int &i: houses){
        cin >> i;
        i *= 2;
    }
    sort(houses.begin(), houses.end());
    int high = houses[n - 1];
    int low = 0;
    vector<int> positions(3);
    while(high - low > 0){
        unsigned int d = (high + low) / 2;
        int index = 0;
        vector<int> temp(3);
        for(int i = 0; i < 3; i++){
            if(index == n) break;
            else {
                temp[i] = houses[index] + d;
                index = upper_bound(houses.begin(), houses.end(), houses[index] + 2 * d) - houses.begin();
            }
        }

        if(index == n){
            high = d;
            for(int i = 0; i < 3; i++){
                positions[i] = temp[i];
            }
        } else low = d + 1;
    }
    cout << low / 2 << ((low % 2 == 1) ? ".500000" : ".000000") << endl;
    cout << positions[0] / 2 << ((positions[0] % 2 == 1) ? ".500000" : ".000000") << " ";
    cout << positions[1] / 2 << ((positions[1] % 2 == 1) ? ".500000" : ".000000") << " ";
    cout << positions[2] / 2 << ((positions[2] % 2 == 1) ? ".500000" : ".000000");
}