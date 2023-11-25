#include <bits/stdc++.h>
using namespace std;

int main(){
    set<int> nums;
    int n;
    cin >> n;
    while(n--){
        int num;
        cin >> num;
        nums.insert(num);
    }
    cout << nums.size();
}