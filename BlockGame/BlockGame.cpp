#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main(){
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);
    int n;
    cin >> n;

    int total[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    
    for(int c = 0; c < n; c++){
        array<int, 26> temp1;
        array<int, 26> temp2;
        temp1.fill(0);
        temp2.fill(0);
        string a, b;
        cin >> a >> b;
        for(int c2 = 0; c2 < a.length(); c2++){
            char ch = a.at(c2);
            temp1[int(ch)-97]++;
        }
        for(int c2 = 0; c2 < b.length(); c2++){
            char ch = b.at(c2);
            temp2[int(ch)-97]++;
        }
        for(int index = 0; index < 26; index++){
            total[index] += max(temp1[index], temp2[index]);
        }
    }

    for(int i = 0; i < 26; i++){
        cout << total[i] << "\n";
    }

    return 0;
}