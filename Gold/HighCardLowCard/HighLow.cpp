#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    int n;
    cin >> n;
    set<int> cards;
    for(int i = 1; i <= 2*n; i++){
        cards.insert(i);
    }
    vector<int> first_half;
    vector<int> second_half;
    for(int i = 0; i < n; i++){
        int c;
        cin >> c;
        if(i < n / 2) first_half.push_back(c);
        else second_half.push_back(c);
        cards.erase(cards.find(c));
    }
    sort(first_half.begin(), first_half.end());
    sort(second_half.begin(), second_half.end());

    int score = 0;
    
    vector<int> bessy;
    bessy.assign(cards.begin(), cards.end());
    int b_index = bessy.size() - 1;
    int e_index = first_half.size() - 1;

    while(e_index >= 0){
        if(bessy[b_index] > first_half[e_index]){
            score++;
            b_index--;
        }
        e_index--;
    }

    b_index = 0;
    e_index = 0;
    while(e_index < second_half.size()){
        if(bessy[b_index] < second_half[e_index]){
            score++;
            b_index++;
        }
        e_index++;
    }

    cout << score;
}