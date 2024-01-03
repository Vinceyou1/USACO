#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 500;
int preferences[MAX_N][MAX_N];
int gift_to_index[MAX_N][MAX_N]; // cow, gift to preference index;
int best_gift[MAX_N];
bool visited[MAX_N];

vector<int> DFS(int index){
    visited[index] = true;
    vector<int> ans; ans.push_back(index);
    for(int i = 0; i < gift_to_index[index][index]; i++){
        int cow = preferences[index][i];
        if(!visited[cow]){
            if(gift_to_index[cow][index] < gift_to_index[cow][cow]){
                auto v = DFS(cow);
                for(int in: v){
                    ans.push_back(in);
                }
            }
        }
    }
    return ans;
}

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> preferences[i][j];
            preferences[i][j]--;
            gift_to_index[i][preferences[i][j]] = j;
        }
        best_gift[i] = i;
    }

    for(int i = 0; i < n; i++){
        auto v = DFS(i);
        if(v.size() > 1){
            for(int j = 0; j < v.size(); j++){
                int curr_best_gift = best_gift[v[j]];
                int curr_best_index = gift_to_index[v[j]][curr_best_gift];
                for(int k = 0; k < v.size(); k++){
                    if(gift_to_index[v[j]][v[k]] < curr_best_index){
                        curr_best_gift = v[k];
                        curr_best_index = gift_to_index[v[j]][v[k]];
                    }
                }
                best_gift[v[j]] = curr_best_gift;
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << best_gift[i] + 1 << endl;
    }

    // for(int i = 0; i < n; i++){
    //     int earlier_possible = -1;
    //     for(int j = 0; j < curr_gift_index[i]; j++){
    //         int cow = preferences[i][j];
    //         for(int k = 0; k <= curr_gift_index[cow]; k++){
    //             if(preferences[cow][k] == i) earlier_possible = cow;
    //         }
    //         if(earlier_possible != -1) break;
    //     }
    //     if(earlier_possible != -1){
    //         cout << earlier_possible + 1;
    //     } else {
    //         cout << i + 1;
    //     } cout << endl;
    // }
}