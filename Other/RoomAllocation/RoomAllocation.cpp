#include <bits/stdc++.h>
using namespace std;

int rooms[200000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    multiset<pair<int, int>> in; // pair(time, index)
    multiset<pair<int, int>> out; // pair(time, index)
    int max_room_reached = 0;
    queue<int> available_rooms;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        in.insert({a, i});
        out.insert({b, i});
    }
    auto it_in = in.begin();
    auto it_out = out.begin();
    int time = (*it_in).first;
    while(time <= (*--out.end()).first){
        
        while((*it_in).first == time){
            if(available_rooms.size() == 0){
                max_room_reached++;
                rooms[(*it_in).second] = max_room_reached;
            }
            else{
                rooms[(*it_in).second] = available_rooms.front();
                available_rooms.pop();
            }
            it_in++;
            if(it_in == in.end()){
                break;
            }
        }
        if(it_in == in.end()){
            break;
        }
        while((*it_out).first == time){
            available_rooms.push(rooms[(*it_out).second]);
            it_out++;
        }
        time = min((*it_in).first, (*it_out).first);
    }
    cout << max_room_reached << endl;
    for(int i = 0; i < n; i++){
        cout << rooms[i] << " ";
    }
    return 0;
}