#include <bits/stdc++.h>
using namespace std;

const long long MAX_N = 200000;
long long n;
long long bales[MAX_N];
vector<long long> roads[MAX_N];
long long eq;
vector<long long> receiving[MAX_N];
vector<pair<long long, long long>> outgoing[MAX_N];
long long num = 0;

long long solve(long long index, long long prev)
{
    long long dif = bales[index] - eq;
    for(long long i: roads[index]){
        if(i == prev) continue;
        long long res = solve(i, index);
        if(res > 0) {
            receiving[index].push_back(i);
            outgoing[i].push_back({res, index});
            num++;
        } else if(res < 0){
            receiving[i].push_back(index);
            outgoing[index].push_back({-res, i});
            num++;
        }
        dif += res;
    }
    return dif;
}

bool visited[MAX_N];
void ans(long long index){
    visited[index] = true;
    for(long long i: receiving[index]){
        if(visited[i]) continue;
        ans(i);
    }
    for(auto i: outgoing[index]){
        cout << index + 1 << " " << i.second + 1 << " " << i.first << endl;
    }
}

int main()
{
    cin >> n;
    long long sum = 0;
    for(long long i = 0; i < n; i++) {
        cin >> bales[i];
        sum += bales[i];
    }
    for(long long i = 1; i < n; i++){
        long long u, v; cin >> u >> v;
        u--; v--;
        roads[u].push_back(v);
        roads[v].push_back(u);
    }

    eq = sum / n;
    solve(0, -1);
    cout << num << endl;
    for (int i = 0; i < n; i++) {
		if (!visited[i]) { ans(i); }
	}
}