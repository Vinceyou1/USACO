#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);

    int N, M, R;
    cin >> N >> M >> R;
    vector<int> cows(N);
    for(int i = 0; i < N; i++){
        cin >> cows[i];
    }
    
    vector<pair<int, int>> shops(M);
    for(int i = 0; i < M; i++){
        int q, p;
        cin >> q >> p;
        shops[i] = make_pair(p, q);
    }
    vector<int> rent(R);
    for(int i = 0; i < R; i++){
        cin >> rent[i];
    }
    
    sort(cows.begin(), cows.end());
    sort(shops.begin(), shops.end());
    sort(rent.begin(), rent.end());

    long long total = 0;
    int shop_index = shops.size() - 1;
    int rent_index = rent.size() - 1;
    int cow_index = cows.size() - 1;
    int cow_end = 0;
    while(cow_index >= cow_end){
        int shop_price = 0;
        int milk = cows[cow_index];
        int temp_shop_index = shop_index;
        int temp_shop_amt = 0;
        while(milk > 0){
            if(temp_shop_index < 0) break;
            if(milk >= shops[temp_shop_index].second){
                shop_price += shops[temp_shop_index].first * shops[temp_shop_index].second;
                milk -= shops[temp_shop_index].second;
                temp_shop_index--;
            } else {
                shop_price += shops[temp_shop_index].first * milk;
                temp_shop_amt = shops[temp_shop_index].second - milk;
                milk = 0;
            }
        }
        if(rent_index < 0 || shop_price >= rent[rent_index]){
            // cout << "shop: " << shop_price << endl;
            total += shop_price;
            shop_index = temp_shop_index;
            if(temp_shop_amt){
                shops[shop_index].second = temp_shop_amt;
            }
            cow_index--;
        }
        else{
            // cout << "rent: " << rent[rent_index] << endl;
            cow_end++;
            total += rent[rent_index];
            rent_index--;
        }
    }
    cout << total;
}