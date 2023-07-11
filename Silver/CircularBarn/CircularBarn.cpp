#include <bits/stdc++.h>
using namespace std;
const int mx = 5000000;
bool composite[mx];
int max_prime_mod_4[] = {0, 1, 2, 3};

int main(){
    vector<int> turns;
    turns.push_back(0); turns.push_back(1);
    // Sieve of Eratosthenes
    for(int i = 2; i < mx; i++){
        if(!composite[i]){
            for(int j = 2 * i; j <= mx; j += i){
                composite[j] = true;
            }
            max_prime_mod_4[i % 4] = i;
        }
        if(i % 4 == 0){
            turns.push_back(i / 2);
        } else{
            turns.push_back((i - max_prime_mod_4[i % 4]) / 2 + 1);
        }
    }
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int min_turns = INT32_MAX;
        for(int i = 0; i < n; i++){
            int a; cin >> a;
            if(turns[a] / 2 < min_turns / 2) min_turns = turns[a];
        }
        if(min_turns % 2 == 1) {
            cout << "Farmer John";
        } else cout << "Farmer Nhoj";
        cout << "\n";
    }
    
}