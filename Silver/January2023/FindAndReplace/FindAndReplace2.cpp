#include <bits/stdc++.h>
using namespace std;

int getKeystrokesNeeded(int input[52], array<vector<int>, 52> output){
    int total = 0;
    int index = -1;
    for(auto vect: output){
        index++;
        if(vect.size() > 0){
            for(int in: vect){
                if(in == index) continue;
                if(input[in] == -1) continue;
                if(input[index] == -1){
                    total++;
                } else {
                    if(output.at(input[index]).size() > 0){
                        input[index] = -1;
                        total++;
                    } else total+=2;
                    // } else if(available > 0){
                    //     total+=2;
                    // } else {
                    //     total = -1;
                    //     break;
                    // }
                }
            
            }
        }
        if(total = -1) break;
    }
    cout << total;
    return 2;
}

int main(){
    int t;
    cin >> t;

    

    for(int i = 0; i < t; i++){
        string s1, s2;
        cin >> s1 >> s2;
        int input[52];
        for(int c = 0; c < 52; c++){
            input[c] = -1;
        }
        array<vector<int>, 52> output;
        int total = 0;
        for(int c = 0; c < s1.length(); c++){
            int i1 = s1.at(c) - 'A';
            int i2 = s2.at(c) - 'A';
            if(input[i1] == -1){
                input[i1] = i2;
                bool there = false;
                for(int here: output.at(i2)){
                    if(here==i1) there = true;
                }
                if(!there) output.at(i2).push_back(i1);
            }
            else {
                total = -1;
                break;
            }
            if(c==s1.length()-1){
                total = getKeystrokesNeeded(input, output);
            }
        }
        cout << total;
    }
    return 0;
}