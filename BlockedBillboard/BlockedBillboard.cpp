#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main(){
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    pair<pair<int, int>, pair<int, int>> first;
    pair<pair<int, int>, pair<int, int>> second;
    pair<pair<int, int>, pair<int, int>> block;

    cin >> first.first.first >> first.first.second >> first.second.first >> first.second.second >> second.first.first >>
        second.first.second >> second.second.first >> second.second.second >> block.first.first >> block.first.second >>
        block.second.first >> block.second.second;

    int area1;
    int area2;

    if(first.first.first > block.first.first){
        if(first.second.first < block.second.first){
            if(first.first.second > block.first.second){
                if(first.second.second < block.second.second){
                    area1 = (first.second.first - first.first.first)*(first.second.second-first.first.second);
                } else (first.second.first - first.first.first)*(block.second.second-first.second.)
            }
        }
    }

    cout << area1 + area2;

    return 0;
}