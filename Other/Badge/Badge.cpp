#include <bits/stdc++.h>
using namespace std;

int connections[1001];
int ans[1001];
bool visited[1001];

int eval(int i){
    if(ans[i]) return ans[i];
    vector<int> locations;
    while(!visited[i]){
        locations.push_back(i);
        visited[i] = true;
        i = connections[i];
    }
    if(!ans[i]){
        ans[i] = i;
        int c = 0;
        while(locations[c] != i){
            ans[locations[c]] = ans[i];
            c++;
        }
        for(int index = c+1; index < locations.size(); index++){
            ans[locations[index]] = locations[index];
        }
    } else {
        for(int l: locations){
            ans[l] = ans[i]; 
        }
    }
    return ans[locations[0]];
}

int main(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> connections[i];
    }
    for(int i = 1; i <= n; i++){
        cout << eval(i) << " ";
    }
}