#include <bits/stdc++.h>
using namespace std;


char arr[100][200];
int n, m;

bool consistent(int c){
    bool ACTG[] = {true, true, true, true};
    for(int index = 0; index < n; index++){
        char ch = arr[c][index];
        switch(ch){
            case 'A':
            ACTG[0] = false;
            break;
            case 'C':
            ACTG[1] = false;
            break;
            case 'T':
            ACTG[2] = false;
            break;
            case 'G':
            ACTG[3] = false;
            break;
        }
    }
    for(int index = n; index < 2*n; index++){
        char ch = arr[c][index];
        switch(ch){
            case 'A':
            if(ACTG[0] == false) return false;
            break;
            case 'C':
            if (ACTG[1] ==  false) return false;
            break;
            case 'T':
            if (ACTG[2] ==  false) return false;
            break;
            case 'G':
            if (ACTG[3] ==  false) return false;
            break;
        }
    }
    return true;
}

int main(){
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    
    
    cin >> n >> m;
    for (int c2 = 0; c2 < 2*n; c2++){
        for(int c1 = 0; c1 < m; c1++){
            cin >> arr[c1][c2];
        }
    }
    
    int answer = 0;
    for(int c = 0; c < m; c++){
        if(consistent(c)){
            answer++;
        }
    }

    cout << answer;
    
    return 0;
}