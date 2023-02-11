#include <bits/stdc++.h>
using namespace std;

vector<long> passes;

int main(){
    int n;
    cin >> n;
    passes.push_back(0);
    for(int i = 0; i < n; i++){
        long l;
        cin >> l;
        passes.push_back(l);
    }
    
    
    int index = 0;
    while(passes.at(1) > 0){
        if(index == n){
            cout << 'L';
            passes.at(index)--;
            index--;
        }
        else{
            if(passes.at(index) <= passes.at(index+1)){
                cout << 'R';
                passes.at(++index)--;
            } else {
                cout << 'L';
                passes.at(index)--;
                index--;
            }
        }
    }
    return 0;
}