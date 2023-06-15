// This is NOT solved

#include <bits/stdc++.h>
using namespace std;

int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
    set<pair<int, int>> bits; // index, length
    string s;
    cin >> s;
    char curr_char = s[0];
    int curr_length = 0;
    int last_index = 0;
    for(int i = 0; i < s.size(); i++){
        char c = s[i];
        if(c == curr_char){
            curr_length++;
        } else {
            bits.insert({last_index, curr_length});
            last_index = i;
            curr_length = 1;
        }
    }
    bits.insert({last_index, curr_length});

    
    multiset<int> lengths;
    for(auto it = bits.begin(); it != bits.end(); it++){
        lengths.insert((*it).second);
    }

    int m;
    cin >> m;
    while(m--){
        int n;
        cin >> n;
        n--;
        auto low = bits.lower_bound({n, 0});
        
        if(n == (*low).first){
            if(low == bits.begin()){
                if((*low).second == 1){
                    bits.erase(low);
                    bits.insert({0, (*bits.begin()).second + 1});
                    bits.erase(++bits.begin());
                    lengths.erase(lengths.find(1));
                    lengths.erase(lengths.find((*bits.begin()).second - 1));
                    lengths.insert((*bits.begin()).second);
                } else {
                    int length = (*bits.begin()).second;
                    bits.insert({1, length - 1});
                    lengths.insert(length - 1);
                    bits.erase(low);
                    lengths.erase(lengths.find(length));
                    bits.insert({0, 1});
                    lengths.insert(1);
                }
            }
            else if(low == --bits.end() && (*low).second == 1){
                bits.erase(low);
                lengths.erase(lengths.find(1));
                auto last = --bits.end();
                auto pair = (*last);
                bits.erase(last);
                lengths.erase(lengths.find(pair.second));
                bits.insert({pair.first, pair.second + 1});
            } else if((*low).second == 1){
                cout << "here";
            }
            else {
                auto p2 = (*low);
                auto p1 = (*--low);
                bits.erase(low);
                lengths.erase(lengths.find(p1.second));
                bits.erase(++low);
                lengths.erase(lengths.find(p2.second));
                bits.insert({p1.first, p1.second + 1});
                lengths.insert(p1.second+1);
                bits.insert({p2.first+1, p2.second-1});
                lengths.insert(p2.second-1);
            }
        }
        else{
            if(n == s.size() - 1){
                auto p = *--bits.end();
                bits.erase(*--bits.end());
                lengths.erase(lengths.find(p.second));
                bits.insert({p.first, p.second - 1});
                lengths.insert(p.second - 1);
                bits.insert({s.size() - 1, 1});
                lengths.insert(1);
            }
            else if(low != --bits.end() && (*++low).first == n + 1){
                auto p1 = *low;
                auto p2 = *++low;
                bits.erase(low);
                bits.erase(--low);
                lengths.erase(lengths.find(p2.second));
                lengths.erase(lengths.find(p1.second));
                bits.insert({p1.first, p1.second - 1});
                bits.insert({p2.first - 1, p2.second + 1});
                lengths.insert(p1.second-1);
                lengths.insert(p2.second+1);
            } else {
                auto p = *low;
                bits.erase(low);
                lengths.erase(lengths.find(p.second));
                bits.insert({p.first, n - p.first});
                lengths.insert(n - p.first);
                bits.insert({n, 1});
                lengths.insert(1);
                bits.insert({n+1, p.first + p.second - 1 - n});
                lengths.insert(p.first + p.second - 1 - n);
            }
        }
        cout << *--lengths.end() << " ";
    }
}