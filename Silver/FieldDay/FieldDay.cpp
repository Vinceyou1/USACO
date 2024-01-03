#include <bits/stdc++.h>
using namespace std;

int main(){
    int c, n;
    cin >> c >> n;
    vector<string> teams(n);
    for(auto &i: teams) cin >> i;
    vector<int> bitmask(n);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < c; ++j){
            if(teams[i].at(j) == 'H'){
                bitmask[i] += 1 << j;
            }
        }
    }
    int inverse_op = 0;
    for(int i = 0; i < c; ++i){
        inverse_op += 1 << i;
    }
    vector<int> inverses(n);
    for(int i = 0; i < n; ++i){
        inverses[i] = bitmask[i] ^ inverse_op;
    }
    vector<int> min_distance(1 << c, INT32_MAX);
    for(int i: bitmask) min_distance[i] = 0;

    for(int bit = 0; bit < c; bit++){
        for(int bmask = 0; bmask < (1 << c); bmask++){
            if(min_distance[bmask] != INT32_MAX){
                min_distance[bmask ^ (1 << bit)] = min(min_distance[bmask ^ (1 << bit)], min_distance[bmask] + 1);
            }
        }
    }
    for(int i = 0; i < n; ++i){
        cout << c - min_distance[inverses[i]] << endl;
    }
}