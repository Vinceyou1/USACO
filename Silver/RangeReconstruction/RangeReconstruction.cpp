#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n; cin >> n;
    vector<long long> ranges[n];
    for(long long i = 0; i < n; i++){
        for(long long j = i; j < n; j++){
            long long r; cin >> r;
            ranges[i].push_back(r);
        }
    }
    vector<long long> array;
    array.push_back(1);
    for(long long i = 1; i < n; i++){
        long long p1 = array[i - 1] + ranges[i - 1].at(1);
        long long p2 = array[i - 1] - ranges[i - 1].at(1);
        bool p1_possible = true;
        bool p2_possible = true;
        for(long long j = 0; j < i; j++){
            long long max = array[j] + ranges[j].at(i - j);
            long long min = array[j] - ranges[j].at(i - j);
            if(p1 > max || p1 < min) p1_possible = false;
            if(p2 > max || p2 < min) p2_possible = false;
        }
        if(p1_possible) {array.push_back(p1);}
        else if(p2_possible) {array.push_back(p2);}
    }
    long long minimum = 0;
    long long maximum = 0;
    for(long long i = 0; i < n; i++){
        minimum = min(minimum, array[i]);
        maximum = max(maximum, array[i]);
    }
    const int max_range = 1000000000;
    if(minimum < -max_range){
        for(long long i = 0; i < n; i++){
            array[i] -= (minimum + max_range);
        }
    }
    else if(maximum > 1000000000){
        for(long long i = 0; i < n; i++){
            array[i] -= (maximum - max_range);
        }
    }
    for(long long i = 0; i < n; i++){
        cout << array[i];
        if(i != n - 1) cout << " ";
    }
}