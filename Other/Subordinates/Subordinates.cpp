#include <bits/stdc++.h>
using namespace std;

vector<int> subordinates[200000];
int total[200000];

int find_subordinates(int i){
    for(auto s: subordinates[i]){
        total[i] += find_subordinates(s);
    }
    return 1 + total[i];
}

int main(){
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        int s;
        cin >> s;
        s--;
        subordinates[s].push_back(i);
    }
    find_subordinates(0);
    for(int i = 0; i < n; i++){
        cout << total[i] << " ";
    }

}