#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> cows;
vector<pair<int, int>> stores; // price, quantity
vector<int> neighbors;
vector<int> prefix_quantity; // prefix of stores quantity left
vector<ll> prefix_price; // prefix of stores prices available

// ll store_price(int cow_index){
//     if(cows.at(cow_index) >= prefix_quantity.at(prefix_quantity.size()-1)){
//         return prefix_price.at(prefix_price.size() - 1);
//     }
//     ll price = 0;
//     int upper_bound = lower_bound(prefix_quantity.begin(), prefix_quantity.end(), prefix_quantity.at(prefix_quantity.size() - 1) - cows.at(cow_index)) - prefix_quantity.begin();
//     price += prefix_price.at(prefix_price.size() - 1) - prefix_price.at(upper_bound + 1);
//     int quantity_left = cows.at(cow_index) - prefix_quantity.at(prefix_quantity.size() - 1) + prefix_quantity.at(upper_bound + 1);
//     price += quantity_left * stores.at(upper_bound).first;
//     return price;
// }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("rental.in", "r", stdin);
    // freopen("rental.out", "w", stdout);

    int N, M, R;
    cin >> N >> M >> R;
    for(int i = 0; i < N; i++){
        int g;
        cin >> g;
        cows.push_back(g);
    }
    sort(cows.begin(), cows.end());

    for(int i = 0; i < M; i++){
        int q, p;
        cin >> q >> p;
        stores.push_back(make_pair(p, q));
    }
    sort(stores.begin(), stores.end());

    // prefixes
    prefix_quantity.push_back(0);
    prefix_price.push_back(0);
    for(int i = 1; i <= M; i++){
        prefix_quantity.push_back(prefix_quantity.at(i-1) + stores.at(i-1).second);
        prefix_price.push_back(prefix_price.at(i-1) + stores.at(i-1).first * stores.at(i-1).second);
    }

    for(int i = 0; i < R; i++){
        int r;
        cin >> r;
        neighbors.push_back(r);
    }
    sort(neighbors.begin(), neighbors.end());

    
    ll total = 0;
    int last_cow_index = 0;
    while(cows.size() > 0){
        int cow_index = cows.size() - 1;
        if(cows.at(cow_index) == 0) break;
        ll price = 0;
        int upper_bound;
        int quantity_left = 0;
        if(cows.at(cow_index) >= prefix_quantity.at(prefix_quantity.size()-1)){
            price = prefix_price.at(prefix_price.size() - 1);
            upper_bound = -1;
        }
        else{
            upper_bound = lower_bound(prefix_quantity.begin(), prefix_quantity.end(), prefix_quantity.at(prefix_quantity.size() - 1) - cows.at(cow_index)) - prefix_quantity.begin();
            price += prefix_price.at(prefix_price.size() - 1) - prefix_price.at(upper_bound);
            quantity_left = cows.at(cow_index) - prefix_quantity.at(prefix_quantity.size() - 1) + prefix_quantity.at(upper_bound);
            // cout << quantity_left;
            price += quantity_left * stores.at(upper_bound - 1).first;
        }
        
        int neighbor_price = 0;
        if(neighbors.size() > 0) neighbor_price = neighbors.at(neighbors.size() - 1);
        // cout << price;
        if(price == 0 && neighbor_price == 0) break;
        if(price > neighbor_price){
            // cout << "milk";
            total += price;
            while(stores.size() - 1 > upper_bound){
                stores.pop_back(); prefix_quantity.pop_back(); prefix_price.pop_back();
            }
            if(stores.size() > 0 && quantity_left > 0){
                stores.at(stores.size() - 1).second -= quantity_left;
                prefix_quantity.at(prefix_quantity.size()-1) -= quantity_left;
                prefix_price.at(prefix_price.size() - 1) -= stores.at(stores.size() - 1).first * quantity_left;
            }
            cows.pop_back();
        } else {
            
            while(neighbors.size() > 0 && price <= neighbors.at(neighbors.size() - 1)){
                // cout << "rent: " << neighbors.at(neighbors.size() - 1);
                if(last_cow_index > cows.size() - 1) break;
                total += neighbors.at(neighbors.size() - 1);
                neighbors.pop_back();
                cows.at(last_cow_index) = 0;
                last_cow_index++;
            }
        }
    }
    cout << total;

}