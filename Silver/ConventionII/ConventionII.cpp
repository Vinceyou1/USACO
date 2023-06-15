#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);
    int n;
    cin >> n;
    set<tuple<int, int, int>> cows; // Arrival time, duration, seniority
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        cows.insert({a, b, n - i});
    }

    int current_time = 0;
    int max_wait = 0;
    priority_queue<tuple<int, int, int>> priority; // seniority, arrival time, duration
    while(cows.size() > 0){
        auto cow = cows.begin();
        auto temp = cow;
        while(get<0>(*cow) < current_time && cow != cows.end()){
            priority.push({get<2>(*cow), get<0>(*cow), get<1>(*cow)});
            cow++;
        }
        if(priority.empty()){
            current_time = max(get<0>(*cow), current_time);
            current_time += get<1>(*cow);
            cows.erase(cows.begin());
        } else {
            while(!priority.empty()){
                auto top = priority.top();
                max_wait = max(max_wait, current_time - get<1>(top));
                current_time += get<2>(top);
                cows.erase(cows.find({get<1>(top), get<2>(top), get<0>(top)}));
                priority.pop();
                while(get<0>(*cow) < current_time && cow != cows.end()){
                    priority.push({get<2>(*cow), get<0>(*cow), get<1>(*cow)});
                    cow++;
                }
            }
        }
    } 
    cout << max_wait;
}