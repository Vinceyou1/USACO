#include <bits/stdc++.h>
using namespace std;

bool dir[1500][1500];
int prices[1500][1500];
int feeds_right[1500];
int feeds_bottom[1500];
int n;

void generateBranches(int i, int i2, bool direction, int price){
    if(i == -1 || i2 == -1) return;
    if(dir[i][i2] == direction) {
        prices[i][i2] = price;
        generateBranches(i-1, i2, true, price);
        generateBranches(i, i2-1, false, price);
    }
}

void generateBranchesBottom(int i){
    if(dir[i][n-1] == false){
        prices[i][n-1] = feeds_bottom[i];
        generateBranches(i-1, n-1, true, feeds_bottom[i]);
        generateBranches(i, n-2, false, feeds_bottom[i]);
    }
}

void generateBranchesRight(int i){
    if(dir[n-1][i] == true){
        prices[n-1][i] = feeds_right[i];
        generateBranches(n-2, i, true, feeds_right[i]);
        generateBranches(n-1, i-1, false, feeds_right[i]);
    }
}



int main(){
    cin >> n;
    for(int i = 0; i <= n; i++){
        for(int i2 = 0; i2 <= n; i2++){
            if(i == n && i2 == n){
                break;
            }
            else{
                if(i2 == n){
                    cin >> feeds_right[i];
                } else if(i == n){
                    cin >> feeds_bottom[i2];
                } else{
                    char c;
                    cin >> c;
                    if(c =='R') dir[i2][i] = true;
                    else dir[i2][i] = false;
                }
                
            }
        }
    }
    

    int total_price = 0;
    for(int i = 0; i < n; i++){
        generateBranchesRight(i);
        generateBranchesBottom(i);
        
    }
    
    for(int i = 0; i < n; i++){
        for(int i2 = 0; i2 < n; i2++){
            total_price += prices[i][i2];
        }
    }
    cout << total_price << endl;

    int t;
    cin >> t;
    for (int c = 0; c < t; c++){
        int i, j;
        cin >> j >> i;
        i--;
        j--;
        int total_price = 0;
        if(i != n -1 && j != n-1){
            if(dir[i][j]){
                prices[i][j] = prices[i][j+1];
            } else{
                prices[i][j] = prices[i+1][j];
            }
        } else {
            if(i == n-1){
                if(dir[i][j]){
                    prices[i][j] = prices[i][j+1];
                } else{
                    prices[i][j] = feeds_right[j];
                }
            }
            if(j == n-1){
                if(dir[i][j]){
                    prices[i][j] = feeds_bottom[i];
                } else{
                    prices[i][j] = prices[i+1][j];
                }
            }
        }
        dir[i][j] = !dir[i][j];
        generateBranches(i-1, j, true, prices[i][j]);
        generateBranches(i, j-1, false, prices[i][j]);
    
        for(int i1 = 0; i1 < n; i1++){
            for(int i2 = 0; i2 < n; i2++){
                total_price += prices[i1][i2];
            }
        }
        cout << total_price << endl;
    }
    // for (int i = 0; i < t; i++){
    //     int i1, i2;
    //     cin >> i2 >> i1;
    //     i1--;
    //     i2--;
    //     if(i1 != n -1 && i2 != n-1){
    //         if(dir[i1][i2]){
    //             prices[i1][i2] = prices[i1][i2+1];
    //         } else{
    //             prices[i1][i2] = prices[i1+1][i2];
    //         }
    //     } else {
    //         if(i1 == n-1){
    //             if(dir[i1][i2]){
    //                 prices[i1][i2] = prices[i1][i2+1];
    //             } else{
    //                 prices[i1][i2] = feeds_right[i2];
    //             }
    //         }
    //         if(i2 == n-1){
    //             if(dir[i1][i2]){
    //                 prices[i1][i2] = feeds_bottom[i1];
    //             } else{
    //                 prices[i1][i2] = prices[i1+1][i2];
    //             }
    //         }
    //         dir[i1][i2] = !dir[i1][i2];
    //     }
    //     dir[i1][i2] = !dir[i1][i2];
    //     total_price = 0;
    //     for(int i = 0; i < n; i++){
    //         for(int i2 = 0; i2 < n; i2++){
    //             total_price += prices[i][i2];
    //         }
    //     }
    //     cout << total_price;
    // }

    return 0;
}