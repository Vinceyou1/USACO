#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    vector<vector<int>> col_prefix_100(n, vector<int>(n + 1));
    vector<vector<int>> col_prefix_less(n, vector<int>(n + 1));
    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){
            cin >> grid[col][row];
            col_prefix_100[col][row + 1] = col_prefix_100[col][row];
            col_prefix_less[col][row + 1] = col_prefix_less[col][row];
            if(grid[col][row] == 100) ++col_prefix_100[col][row + 1];
            else if(grid[col][row] < 100) ++col_prefix_less[col][row + 1];
        }
    }
    long long ans = 0;
    for(int row_start = 0; row_start < n; ++row_start){
        for(int row_end = row_start; row_end < n; ++row_end){
            int num_before_100 = 0; // counts the number of elements >= 100 before the last occurence of 100
            int num_after_100 = 0; // temporary variable to store the number we have after the last occurence
            // long long cur_ans = 0; // answer for our current chain
            for(int col = 0; col < n; ++col){
                int number_of_100s = col_prefix_100[col][row_end + 1] - col_prefix_100[col][row_start];
                int number_less_100 = col_prefix_less[col][row_end + 1] - col_prefix_less[col][row_start];
                if(number_less_100){
                    // ans += cur_ans;
                    // cur_ans = 0;
                    num_after_100 = 0;
                    num_before_100 = 0;
                    continue;
                }
                if(number_of_100s){
                    num_before_100 += num_after_100 + 1;
                    num_after_100 = 0;
                    ans += num_before_100;
                } else {
                    ans += num_before_100;
                    num_after_100++;
                }
            }
        }
    }
    cout << ans;
}