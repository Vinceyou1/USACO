#include <bits/stdc++.h>
using namespace std;

int milking[100]{0};
int positions[100]; // Inverse of milking

int main(){
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);
    for(int &i: positions) i = -1;
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> hierarchy;

    bool oneinhierarchy = false;
    for(int i = 0; i < m; i++){
        int a;
        cin >> a;
        if (a == 1) oneinhierarchy = true;
        hierarchy.push_back(a);
    }
    
    for(int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        if(a == 1){ cout << b; return 0; }
        milking[b-1] = a;
        positions[a] = b-1;
    }

    if(oneinhierarchy){
        for(int i = hierarchy.size() - 1; i >= 0; i--){
            if(hierarchy.at(i) == 1){
                for(int j = i - 1; j >= 0; j--){
                    if(positions[hierarchy.at(j)] != -1){
                        int index = positions[hierarchy.at(j)];
                        while(++j != i){
                            while(milking[index] != 0) index++;
                            positions[j] = index;
                            milking[index] = j;
                            index++;
                        }
                        while(milking[index] != 0) index++;
                        cout << index + 1;
                        return 0;
                    }
                }
                // if this is reached none of the indexes before i are "anchored", so put them as soon as possible
                int index = 0;
                for(int j = 0; j <= i; j++){
                    while(milking[index] != 0) index++;
                    milking[index] = hierarchy.at(j);
                    if(j == i) {cout << index + 1; return 0;}
                }
            }
        }
    }
    else{
        for(int i = hierarchy.size() - 1; i >= 0; i--){
            if(positions[hierarchy.at(i)] != -1){
                for(int j = i - 1; j >= 0; j--){
                    if(positions[hierarchy.at(j)] == -1){
                        int index = positions[hierarchy.at(j)+1] - 1;
                        while(index >= 0){
                            if(milking[index] == 0) break;
                            index--;
                        }
                        positions[hierarchy.at(j)] = index;
                        milking[index] = hierarchy.at(j);
                    }
                }
                break;
            }
        }
    }
    // for(int i : milking){
    //     cout << i << " ";
    // }
    // cout << endl;
    for(int i = 0; i < 100; i++){
        if(milking[i] == 1){
            cout << i + 1;
            return 0;
        }
    }
    for(int i = 0; i < 100; i++){
        if(milking[i] == 0){
            cout << i + 1;
            return 0;
        }
    }
}