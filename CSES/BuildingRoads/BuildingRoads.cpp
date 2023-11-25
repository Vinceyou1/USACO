#include <bits/stdc++.h>
using namespace std;

vector<bool> reached_cities;
vector<vector<int>> roads;

void add_reached_cities(int i){
    reached_cities.at(i) = true;
    if(roads.at(i).size()>0){
        for(int city: roads.at(i)){
            if(!reached_cities.at(city)) add_reached_cities(city);
        }
    }
}


int main(){
    int n, r;
    cin >> n >> r;
    roads = vector<vector<int>>(n);

    for(int i = 0; i < n; ++i){
        reached_cities.push_back(false);
    }
    reached_cities.push_back(true);
    for (int i = 0; i < r; ++i){
        int c1, c2;
        cin >> c1 >> c2;
        c1--;
        c2--;
        roads.at(c1).push_back(c2);
        roads.at(c2).push_back(c1);
    }
    int ans = -1;
    vector<int> cities;
    for(int i = 0; i < n; ++i){
        while(reached_cities.at(i)){
            ++i;
            if(i==n) break;
        }
        if(i==n) break;
        if(i != 0){
            cities.push_back(i);
        }
        add_reached_cities(i);
        ++ans;
    }
    cout << ans << "\n";
    for(int i: cities){
        cout << 1 << " " << i + 1 << "\n";
    }

    return 0;
}