#include <bits/stdc++.h>
using namespace std;

char genes[50][1000];
long long answer;
int n, m;
    
void consistent(int c1, int c2, int c3){
    bool tf = false;
    for(int i = 0; i < n; i++){
        string str = string() + genes[c1][i] + genes[c2][i] + genes[c3][i];
        for(int i2 = n; i2 < 2 * n; i2++){    
            string str2 = string() + genes[c1][i2] + genes[c2][i2] + genes[c3][i2];
            if(str.at(0) == str2.at(0) && str.at(1) == str2.at(1) && str.at(2) == str2.at(2)){
                tf = true;
                break;
            }
        }
        if(tf) break;
    }
    if(!tf) ++answer;
}

int main(){
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i < 2 * n; i++){
        for(int i2 = 0; i2 < m; i2++){
            cin >> genes[i2][i];
        }
    }

    for(int c1 = 0; c1 < m; c1++){
        for (int c2 = c1 + 1; c2 < m; c2++){
            for (int c3 = c2 + 1; c3 < m; c3++){
                consistent(c1, c2, c3);
            }
        }
    }

    cout << answer;
    return 0;
}