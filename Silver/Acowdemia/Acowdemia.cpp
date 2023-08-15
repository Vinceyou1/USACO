#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, k, l; cin >> n >> k >> l;
    vector<long long> papers(n);
    for(long long &i: papers) cin >> i;
    sort(papers.begin(), papers.end());
    long long high = n;
    long long low = 0;
    while(high - low > 0){
        long long h = (high + low + 1) / 2;
        long long i = lower_bound(papers.begin(), papers.end(), h) - papers.begin() - 1;
        long long times_cited = 0;
        long long articles_needed = 0;
        while(i >= 0 && i >= papers.size() - h){
            long long diff = h - papers[i];
            times_cited += diff;
            articles_needed = max(articles_needed, diff);
            i--;
        }
        if(times_cited <= k * l && articles_needed <= k){
            low = h;
        } else {
            high = h - 1;
        }
    }
    cout << low;
}