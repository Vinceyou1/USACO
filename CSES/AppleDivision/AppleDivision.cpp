#include <bits/stdc++.h>
using namespace std;

vector<long long> apples;
long long solve(long long basket1, long long basket2, int index){
    if(index==apples.size()){
        return abs(basket1-basket2);
    } else{
        long long apple_weight = apples[index];
        return min(solve(basket1 + apple_weight, basket2, index+1), // Option 1: add apple_weight to basket 1
                   solve(basket1, basket2 + apple_weight, index+1)); // Option 2: add apple_weight to basket 2
    }
}

int main(){
    int n;
    cin >> n;
    for(int c = 0; c < n; c++){
        long long t;
        cin >> t;
        apples.push_back(t);
    }
    cout << solve(0, 0, 0); // basket 1 has weight 0, basket 2 has weight 0, evalutate index 0
    return 0;
}