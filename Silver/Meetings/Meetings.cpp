#include <bits/stdc++.h>
using namespace std;

struct Cow {
    int position, direction, weight;
};

bool cow_cmp(const Cow &a, const Cow &b){
    return a.position < b.position;
}

int main()
{
    freopen("meetings.in", "r", stdin);
    int n, l; cin >> n >> l;
    vector<Cow> cows;
    int total = 0;
    for(int i = 0; i < n; ++i){
        Cow a; cin >> a.weight >> a.position >> a.direction;
        cows.push_back(a);
        total += a.weight;
    }

    sort(cows.begin(), cows.end(), cow_cmp);

    vector<Cow> left_going, right_going;
    for(int i = 0; i < n; ++i){
        if(cows[i].direction == 1){
            right_going.push_back(cows[i]);
        } else left_going.push_back(cows[i]);
    }

    set<pair<int, int>> arrivals; // time, weight
    for(int i = 0; i < left_going.size(); ++i){
        Cow corresponding = cows[i];
        arrivals.insert({left_going[i].position, corresponding.weight});
    }

    for(int i = 0; i < right_going.size(); ++i){
        Cow corresponding = cows[(cows.size() - 1) - (right_going.size() - 1 - i)];
        arrivals.insert({l - right_going[i].position, corresponding.weight});
    }
    
    int time = 0;
    int weight_sum = 0;
    while(weight_sum < (total + 1) / 2){
        weight_sum += (*arrivals.begin()).second;
        time = (*arrivals.begin()).first;
        arrivals.erase(arrivals.begin());
    }

    int ans = 0;
    int meetings = 0;
    int left_cow_index_start = 0;
    int left_cow_index_end = 0;
    for(int i = 0; i < right_going.size(); ++i){
        while(left_cow_index_end < left_going.size() && right_going[i].position + 2 * time >= left_going[left_cow_index_end].position){
            ++meetings;
            ++left_cow_index_end;
        }
        while(left_cow_index_start < left_going.size() && left_going[left_cow_index_start].position < right_going[i].position){
            ++left_cow_index_start;
            --meetings;
        }
        ans += meetings;
    }
    freopen("meetings.out", "w", stdout);
    cout << ans;
}