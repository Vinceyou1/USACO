#include <bits/stdc++.h>
using namespace std;

int main(){
//    pair<int, string> cows[] = {{0, "Bessie"}, {0, "Elsie"}, {0, "Daisy"}, {0, "Gertie"}, {0, "Annabelle"}, {0, "Maggie"}, {0, "Henrietta"}};
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);
    map<string, int> cows;
    int N;
    cin >> N;
    while(N--){
        string s;
        cin >> s;
        int p;
        cin >> p;
        cows[s] += p;
    }
    vector<pair<int, string>> ordered_cows;
    for(auto i: cows){
        ordered_cows.push_back(make_pair(i.second, i.first));
    }
    sort(ordered_cows.begin(), ordered_cows.end());
    if(ordered_cows.size() == 1){ cout << ordered_cows.at(0).second; return 0;}
    int min = ordered_cows.at(0).first;
    int min2 = -1;
    for(int i = 1; i < ordered_cows.size(); i++){
        if(ordered_cows.at(i).first != min){
            if((i < ordered_cows.size() - 1 && ordered_cows.at(i).first != ordered_cows.at(i+1).first) || i == ordered_cows.size() - 1){
                cout << ordered_cows.at(i).second;
                return 0;
            }
        }
    }
    cout << "Tie";
    return 0;
}