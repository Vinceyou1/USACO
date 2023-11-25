#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000000;
int biggest_prime_factor[MAX_N + 1];


int main(){
    // Sieve of erasothenes
    for(int i = 2; i <= MAX_N; i++){
        if(!biggest_prime_factor[i]){
            for(int j = i; j <= MAX_N; j += i){
                biggest_prime_factor[j] = i;
            }
        }
    }


    int n; cin >> n;
    while(n--){
        int x; cin >> x;
        int ans = 1;
        while(x != 1){
            int prime = biggest_prime_factor[x];
            int multiple = 1;
            while(x % prime == 0){
                x /= prime;
                multiple++;
            }
            ans *= multiple;
        }
        cout << ans << endl;
    }
}