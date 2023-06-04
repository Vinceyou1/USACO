#include <bits/stdc++.h>
using namespace std;
//use some sort of coord compression and then keep adding the cows in each G area

vector<pair<int, pair<int, int>>> gardens;

int bin_search_time(int time, int l, int r){
    if(r-l <= 1) return l;
    int t1, t2;
    t1 = gardens.at(l).first;
    t2 = gardens.at(r).first;
    if(time < t1) return -1;
    if(time > t2) return gardens.size()-1;
    int m = (l+r)/2;
    int t3 = gardens.at(m).first;
    if(time < t3) return bin_search_time(time, l, m);
    else if(time > t3) return bin_search_time(time, m, r);
    else return m;
}

bool reachable(int x, int y, int time, int index){
    long long difference = (gardens.at(index).second.first-x) * (gardens.at(index).second.first-x) + (gardens.at(index).second.second-y) * (gardens.at(index).second.second-y);
    return difference  <= (time - gardens.at(index).first) * (time - gardens.at(index).first) ;
}

bool test(int x, int y, int time){
    if(gardens.size() == 1){
        return reachable(x, y, time, 0);
    }
    else{
        int l = bin_search_time(time, 0, gardens.size()-1);
        if(l == -1){
            return reachable(x, y, time, 0);
        }
        if (l == gardens.size()-1){
            return reachable(x, y, time, gardens.size()-1);
        }
        return reachable(x, y, time, l) && reachable(x, y, time, l+1);
    }
}

int main(){
    int G, N;
    cin >> G >> N;
    
    for(int i = 0; i < G; i++){
        int a, b, c;
        cin >> a >> b >> c;
        gardens.push_back(make_pair(c, make_pair(a, b)));
    }
    sort(gardens.begin(), gardens.end());
    int ans = 0;
    for(int i = 0; i < N; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(!test(a, b, c)){
            ans++;
        }
    }
    cout << ans;
}