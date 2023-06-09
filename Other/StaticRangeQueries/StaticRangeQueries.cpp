#include <bits/stdc++.h>
using namespace std;


int bin_search(int i, vector<int> &indices){
    int l = 0; int r = indices.size() - 1; int m;
    if(i < indices.at(l)) return 0;
    return lower_bound(indices.begin(), indices.end(), i) - indices.begin();
    // while(r - l > 1){
    //     int m = (l + r) / 2;
    //     if(reduced.at(m).first > i) r = m;
    //     if(reduced.at(m).first < i) l = m;
    //     if(reduced.at(m).first == i) return m;
    // }
    // if(reduced.at(l).first == i) return l;
    // if(reduced.at(r).first == i) return r;
    // // We now have l and r to the left and right of value i
    // return l;
    
}

int main(){
    int N, Q;
    cin >> N >> Q;
    map<int, int> values;
    while(N--){
        int l, r, v;
        cin >> l >> r >> v;
        while(l < r){
            values[l] += v;
            l++;
        }
    }
    vector<int> indices;
    vector<int> totals;
    for(auto &ele: values){
        indices.push_back(ele.first);
        totals.push_back(ele.second);
        // cout << ele.first << ": " << ele.second << endl;
    }
    vector<long long> prefix;
    prefix.push_back(0);
    for(int i = 1; i <= totals.size(); i++){
        prefix.push_back(totals[i-1] + prefix[i-1]);
    }
    // for(auto i: prefix) cout << i << " ";
    // cout << endl;
    while(Q--){
        int l, r;
        cin >> l >> r;
        int left_index = bin_search(l, indices);
        int right_index = bin_search(r, indices);
        // cout << "left: " << left_index << "right: " << right_index << endl;
        cout << prefix[right_index] - prefix[left_index] << "\n";
    }
    return 0;
}