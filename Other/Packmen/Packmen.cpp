#include <bits/stdc++.h>
using namespace std;


int main(){
    int n; cin >> n;
    vector<int> packmen;
    vector<int> pellets;
    for(int i = 0; i < n; i++){
        char c; cin >> c;
        if(c == '*') pellets.push_back(i);
        else if(c == 'P') packmen.push_back(i);
    }
    int high = 2 * n; int low = 0;
    while(high - low > 0){
        int mid = (high + low) / 2;
        int pellet_index = 0;
        for(int i = 0; i < packmen.size(); i++){
            int temp;
            if(pellets[pellet_index] < packmen[i]){
                int distance = packmen[i] - pellets[pellet_index];
                if(distance > mid) break;
                int if_go_left = mid - 2 * distance;
                int if_go_right = (mid - distance) / 2;
                temp = packmen[i] + max(if_go_left, if_go_right);
            } else {
                temp = packmen[i] + mid;
            }
            while(pellet_index < pellets.size() && pellets[pellet_index] <= temp) pellet_index++;
            if(pellet_index == pellets.size()) break;
        }
        if(pellet_index == pellets.size()){
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << low;
}