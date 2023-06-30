#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll ask(string and_or, ll a, ll b){
    cout << and_or << " " << a << " " << b << endl;
    ll ans; cin >> ans;
    return ans;
}

ll sum(ll a, ll b){
    a++; b++;
    ll AND = ask("and", a, b);
    ll OR = ask("or", a, b);
    ll XOR = ~AND & OR;
    return 2*AND + XOR;
    
}

tuple<ll, ll, ll> system(ll a_plus_b, ll b_plus_c, ll c_plus_a){
    long long sum = (a_plus_b + b_plus_c + c_plus_a) / 2;
    return (make_tuple(sum - b_plus_c, sum - c_plus_a, sum - a_plus_b));
}

int main(){
    vector<ll> numbers;
    ll n, k; cin >> n >> k;
    ll a_plus_b = sum(0, 1);
    ll b_plus_c = sum(0, 2);
    ll c_plus_a = sum(1, 2);
    auto t = system(a_plus_b, b_plus_c, c_plus_a);
    numbers.push_back(get<0>(t)); numbers.push_back(get<1>(t)); numbers.push_back(get<2>(t));
    // cout << numbers[0] << " " << numbers[1] << " " << numbers[2] << endl;
    for(ll i = 3; i < n; i++){
        numbers.push_back(sum(i-1, i) - numbers.back());
        // cout << numbers.back();
    }
    sort(numbers.begin(), numbers.end());
    cout << "finish " << numbers[k-1] << endl;    
}