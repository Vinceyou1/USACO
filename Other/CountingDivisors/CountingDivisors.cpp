#include <bits/stdc++.h>
using namespace std;



int main(){
    vector<int> primes;
    const int MAX_N = 1000000;
    bool composite[MAX_N];
    // Sieve of erasothenes
    for(int i = 2; i < MAX_N; i++){
        if(!composite[i]){
            primes.push_back(i);
            for(int j = i * 2; j < MAX_N; j += i){
                composite[j] = true;
            }
        }
    }
    for(int i : primes){
        cout << i << " ";
    }


    int n; cin >> n;
    while(n--){
        int x; cin >> x;
        int factors = 0;
        for(int f = 1; f <= sqrt(x); f++){
            if(f*f == x) factors--;
            if(x % f == 0) factors += 2;
        }
        cout << factors << endl;
    }
}