#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    int k, n;
    cin >> k >> n;
    vector<pair<int, int>> pairs;
    for (int c = 0; c < k; c++){
        int *arr = new int[n];
        vector<pair<int, int>> temp;
        vector<pair<int, int>> temp2;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        for(int i = 0; i < n; i++){
            for(int i2 = i+1; i < n; i++){
                temp.push_back(make_pair(arr[i], arr[i2]));
            }
        }
        if (c == 0){
            pairs = temp;
        }
        else {
            for (pair<int, int> pair:temp){
                if(find(pairs.begin(), pairs.end(), pair) == pairs.end()){
                    temp2.push_back(pair);
                }
            }
            pairs = temp2;
        }
        cout << pairs.size();
    }
    cout << pairs.size();

    return 0;
}