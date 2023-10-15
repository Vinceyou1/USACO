#include <bits/stdc++.h>
using namespace std;

long long sum(long long length, long long parts){
    long long even_partition_size = length / parts; // underestimate
    long long remainder = length % parts;
    return (parts - remainder) * (even_partition_size * even_partition_size) + remainder * ((even_partition_size + 1) * (even_partition_size + 1));
}

struct carrot_difference {
    long long difference, length, next_size;
    bool operator<(const carrot_difference &y) const { return difference < y.difference; }
};

int main()
{
    int n, k; cin >> n >> k;
    vector<long long> carrots(n);
    for(long long &carrot: carrots) cin >> carrot;
    priority_queue<carrot_difference> pq;
    for(long long i: carrots){
        carrot_difference cd;
        cd.length = i;
        cd.next_size = 2;
        cd.difference = sum(i, 1) - sum(i, 2);
        if(cd.next_size <= cd.length) pq.push(cd);
    }
    long long ans = 0;
    for(long long i: carrots){
        ans += sum(i, 1);
    }
    k -= n;
    while(k--){
        carrot_difference cd = pq.top();
        pq.pop();
        ans -= cd.difference;
        cd.difference = sum(cd.length, cd.next_size) - sum(cd.length, cd.next_size + 1);
        cd.next_size += 1;
        if(cd.next_size <= cd.length) pq.push(cd);
    }
    cout << ans;
}