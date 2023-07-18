#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 801;
int n, k;
int squares[MAX_N][MAX_N];
int prefix[MAX_N][MAX_N];
int min_median = INT32_MAX;

int main(){
    cin >> n >> k;
    int max_height = 0;
    for(int y = 1; y <= n; y++){
        for(int x = 1; x <= n; x++){
            cin >> squares[x][y];
            max_height = max(max_height, squares[x][y]);
        }
    }
    int right = max_height + 1;
    int left = 0;
    while(right - left > 0){
        int mid = (right + left) / 2;
        // cout << mid << endl;
        for(int y = 1; y <= n; y++){
            for(int x = 1; x <= n; x++){
                prefix[x][y] = prefix[x - 1][y] + prefix[x][y - 1] - prefix[x - 1][y - 1];
                if(squares[x][y] > mid) prefix[x][y]++;
            }
        }
        bool possible = false;
        for(int y = k; y <= n; y++){
            for(int x = k; x <= n; x++){
                int total_above_med = prefix[x][y] - prefix[x - k][y] - prefix[x][y - k] + prefix[x - k][y - k];
                // cout << x << " " << y << " " << total_above_med << endl;
                if(total_above_med < (k*k) / 2 + 1) possible = true;
            }
        }
        if(possible){
            right = mid;
        } else left = mid + 1;
    }
    cout << left;
}