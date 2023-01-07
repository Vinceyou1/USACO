#include <bits/stdc++.h>
using namespace std;

vector<char> doRecursion(vector<char> letters){
    vector<char> temp = letters;
    for(int i = 0; i < letters.size(); i++){
        if(i=letters.size()-1){
            if (letters.at(0) == letters.at(letters.size()-1)){
                letters.pop_back();
                letters.erase(letters.begin());
            }
        }
        else{
            if(letters.at(i) == letters.at(i+1)){
                letters.erase(letters.begin()+i, letters.begin()+i+2);
            }
        }
    } 
    if (temp.size() == letters.size()){
        return letters;
    }
    else return doRecursion(letters);
}

int crossingPairs(vector<char> letters){
    
    int pairs = 0;
    while(letters.size() != 0){
        vector<char> temp;
        char first = letters.at(0);
        for (int i = 1; i < letters.size(); i++){
            
            if (letters.at(i) ==  first){
                letters.erase(letters.begin()+i);
                break;
            } else {
                if(find(temp.begin(), temp.end(), letters.at(i))==temp.end()){
                    temp.push_back(letters.at(i));
                    pairs++;
                } else pairs--;
            }
        }
        letters.erase(letters.begin());
    }
    return pairs;
    
}

int main(){
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    vector<char> letters;
    for(int i = 0; i < 52; i++){
        char c;
        cin >> c;
        letters.push_back(c);
    }
    letters = doRecursion(letters);
    cout << crossingPairs(letters);
    return 0;
}