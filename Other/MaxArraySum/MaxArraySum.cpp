#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    iostream::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    long long x;
    cin >> x;
    long long total = x;
    long long running_total = x;

    vector<long long> v(n);
    for(int i = 1; i < n; i++){
        long long num;
        cin >> num;
        running_total += num;
        if(total < max(num, running_total)){
            total = max(num, running_total);
            running_total = total;
        }   
    }
    cout << total;
    return 0;
}