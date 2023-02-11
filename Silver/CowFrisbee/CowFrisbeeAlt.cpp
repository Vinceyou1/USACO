#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> descending;
    int val;
    cin >> val;
    descending.push_back(val);
    long long total = 0;

    for(int c = 0; c < n-1; c++){
        cin >> val;
        if (val < descending[descending.size()-1]){
            descending.push_back(val);
            total+=2;
        }
        else {
            int count = 0;
            while(descending[count] > val) count++;
            int range;
            if(count == 0) range = descending.size()-1-count;
            else range = descending.size()-count;
            cout << (range+1)*(2+(2+range))/2 << " ";
            descending.erase(descending.begin()+count, descending.end());
            descending.push_back(val);
        }
    }

    cout << total;

    return 0;
}