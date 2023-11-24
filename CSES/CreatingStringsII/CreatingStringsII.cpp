#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

long long exp(long long a, int b){
    if(b == 1) return a;
    else if (b == 0) return 1;
    long long half = exp(a, b / 2);
    long long ans = half * half;
    ans %= MOD;
    if(b % 2){
        ans *= a;
        ans %= MOD;
    }
    return ans;
}

long long mod_inverse(long long i){
    return exp(i, MOD - 2);
}

int main(){
    string s; cin >> s;
    vector<int> character_count(26);
    vector<long long> factorials;
    long long ans = 1;
    for(int i = 0; i < s.size(); ++i){
        ans *= (i + 1);
        ans %= MOD;
        factorials.push_back(ans);
        character_count[s[i] - 'a']++;
    }

    for(int i: character_count){
        if(i){
            ans *= mod_inverse(factorials[i - 1]);
            ans %= MOD;
        }
    }
    cout << ans;
}