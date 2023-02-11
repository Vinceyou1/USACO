#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int *nums = new int[n];

    for(int c = 0; c < n; c++){
        cin >> nums[c];
    }
    long long total = 0;
    for(int c = 0; c < n; c++){
        int value = nums[c];
        int min = 0;
        int c1 = c+1;
        if (c1 == n) continue;
        while(nums[c1] < value){
            if(nums[c1] > min){
                total += c1-c+1;
                min = nums[c1];
                
            }
            if(++c1==n) break;
        }
        if (c1 != n) {
            total+=c1-c+1;
        }
    }
    cout << total;
    return 0;
}
