#include <bits/stdc++.h>
using namespace std;

int findKeystrokes(int input[52], array<vector<int>, 52> output){
    int total = 0;
    for(int i = 0; i < 52; i++){
        auto vect = output.at(i);
        if(vect.size() > 0){
            for(int c = vect.size()-1; c > -1; c--){
                int in = vect.at(c);
                vect.pop_back();
                if(in == i){continue;}
                if(input[in] == -1){cout <<'h'; continue;}
                if(input[i] == -1){
                    cout << 'h';
                    total++;
                } else {
                    if(output.at(input[i]).size() > 0){
                        if(output.at(input[i]).size() > 1 || output.at(input[i]).at(0) != in){
                            cout << i;
                            total++;
                        }
                        else total +=2;
                    } else {
                        total+=2;
                    }
                    
                    // } else if(available > 0){
                    //     total+=2;
                    // } else {
                    //     total = -1;
                    //     break;
                    // }
                }
            
            }
        }
        
        if(total == -1) break;
    }
    return total;
}


int main(){
    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        int input[52];
        for(int c = 0; c < 52; c++){
            input[c] = -1;
        }
        array<vector<int>, 52> output;
        int total = 0;
        string s1, s2;
        cin >> s1 >> s2;
        int length = s1.length();
        for(int c = 0; c < length; c++){
            int i1 = s1.at(c) - 'A';
            int i2 = s2.at(c) - 'A';
            if(input[i1] == -1){
                if(i1!=i2){
                    input[i1] = i2;
                    if(find(output.at(i2).begin(), output.at(i2).end(), i1) == output.at(i2).end()){
                        output.at(i2).push_back(i1);
                    }
                }
                    
            } else {
                total = -1;
                break;
            }
            if(c == length-1){
                total = findKeystrokes(input, output);
            }
        }
        cout << total << endl;
    }
    return 0;
}