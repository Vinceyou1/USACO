#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
using namespace std;

vector<string> generatePermutations(vector<char> chars){
    vector<string> perms;
    
    return perms;

}

int main(){
    string st;
    cin >> st;
    vector<char> chars;
    for(int i = 0; i < st.length(); i++){
        chars.push_back(st.at(i));
    }

    auto cperms = generatePermutations(chars);
    cout << cperms.size();

    return 0;
}