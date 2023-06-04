#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> GCD_pre(N);
    vector<int> GCD_suf(N);
    vector<int> nums(N);
    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        nums.at(i) = a;
    }
    GCD_pre.at(0) = nums.at(0);
    for(int i = 1; i < N; i++){
        GCD_pre.at(i) = gcd(GCD_pre.at(i-1), nums.at(i));
    }
    GCD_suf.at(N-1) = nums.at(N-1);
    for(int i = N - 2; i > 0; i--){
        GCD_suf.at(i) = gcd(GCD_suf.at(i+1), nums.at(i));
    }

    int max_GCD = max(GCD_pre.at(N-2), GCD_suf.at(1));
    for(int i = 1; i < N - 1; i++){
        max_GCD = max(max_GCD, gcd(GCD_pre.at(i-1), GCD_suf.at(i+1)));
    }
    cout << max_GCD;
}



// #include <iostream>
// #include <map>
// #include <vector>
// #include <cmath>
// #include <numeric>
// using namespace std;

// vector<long long> get_factors(long long num){
//     vector<long long> f;
//     for(int i = 1; i < sqrt(num); i++){
//         if(num % i == 0){
//             f.push_back(i);
//             f.push_back(num / i);
//         }
//     }
//     return f;
// }

// int main(){
//     int N;
//     cin >> N;
//     map <long long, long long> factors;
//     for(int c = 0; c < N; c++){
//         long long a;
//         cin >> a;
//         for(long long i: get_factors(a)){
//             factors[i]++;
//         }
//     }
//     long long GCD = 1;
//     for(const auto &ele: factors){
//         if(ele.first > GCD && ele.second >= N - 1){ GCD = ele.first;}
//     }
//     cout << GCD;
//     return 0;
// }