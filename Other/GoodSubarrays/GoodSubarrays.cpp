#include <map>
#include <iostream>
#include <string>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        long long prefix = 0;
        map<long long, long long> sums;
        for(int i = 0; i < n; i++){
            char a;
            cin >> a;
            sums[prefix - i]++;
            prefix += a - '0';
        }
        sums[prefix - n]++;
        long long good = 0;
        for(const auto &ele : sums){
            good += ele.second * (ele.second - 1) / 2;
        }
        cout << good << "\n";
    }
}