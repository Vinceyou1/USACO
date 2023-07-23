#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<int> attack;
    vector<int> defense;
    while(n--){
        string pos; int strength; cin >> pos >> strength;
        if(pos == "ATK") attack.push_back(strength);
        else defense.push_back(strength);
    }
    vector<int> fox;
    while(m--){
        int strength;
        cin >> strength;
        fox.push_back(strength);
    }
    sort(attack.begin(), attack.end());
    sort(defense.begin(), defense.end());
    sort(fox.begin(), fox.end());

    // calculate max w/out accounting defense
    int total_no_defense = 0;
    int fox_index = fox.size() - 1;
    auto attack_index = 0;
    while(fox_index >= 0 && attack_index < attack.size() && fox[fox_index] > attack[attack_index]){
        total_no_defense += fox[fox_index] - attack[attack_index];
        fox_index--; attack_index++;
    }


    // calculate max accounting defense
    int total_after_defense = 0;
    bool defense_clearable = true;
    for(int i = defense.size() - 1; i > - 1; i--){
        auto fox_card = upper_bound(fox.begin(), fox.end(), defense[i]);
        if(fox_card == fox.end()){
            defense_clearable = false;
            break;
        } else {
            fox.erase(fox_card);
        }
    }
    if(defense_clearable){
        bool attack_clearable = true;
        for(int i = attack.size() - 1; i > -1; i--){
            auto fox_card = lower_bound(fox.begin(), fox.end(), attack[i]);
            if(fox_card == fox.end()){
                attack_clearable = false;
                break;
            } else {
                total_after_defense += *fox_card - attack[i];
                fox.erase(fox_card);
            }
        }
        if(attack_clearable){
            for(auto i: fox){
                total_after_defense += i;
            }
        }
    }
    cout << max(total_after_defense, total_no_defense);
}