#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
vector<long long> nums;

long minDiff(long long p1, long long p2, int index){
    if (index==nums.size()){
        return abs(p1-p2);
    } else{
        return min(minDiff(p1+nums.at(index), p2, index+1), minDiff(p1, p2+nums.at(index), index+1));
    }
}

int main(){
    cin >> n;
    for(int c = 0; c < n; c++){
        long long t;
        cin >> t;
        nums.push_back(t);
    }
    cout << minDiff(0, 0, 0);
    return 0;
}