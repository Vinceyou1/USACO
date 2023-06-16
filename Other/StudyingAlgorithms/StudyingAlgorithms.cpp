#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> algos;
    while(n--){
        int a;
        cin >> a;
        algos.push_back(a);
    }
    sort(algos.begin(), algos.end());
    int time = 0;
    int index = 0;
    int ans = 0;
    while(time <= x){
	    time += algos[index++];
        ans++;
	    if(index == algos.size()) break;
	    if(time > x){ans--; break;}
    }
    cout << ans;
}