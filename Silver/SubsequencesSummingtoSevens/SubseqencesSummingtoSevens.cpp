#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream fin("div7.in");
    ofstream fout("div7.out");

    int n;
    fin >> n;
    vector<int> prefixes = vector<int>(n);
    int t = 0;
    int temp;
    for(int i = 0; i < n; i++){
        fin >> temp;
        t += temp;
        t %= 7;
        prefixes.at(i) = t;
    }

    int answer = 0;
    for(int i = 0; i < n; i++){
        for(int c = 0; c < i; c++){
            if(prefixes.at(i)-prefixes.at(c) == 0){
                answer = max(answer, i-c);
                break;
            }
        }
    }
    fout << answer;
    return 0;

}