#include <bits/stdc++.h>
using namespace std;

int main(){
    int state;
    cout << "? 0 0" << endl;
    cin >> state;
    int num1 = 0;
    int num2 = 0;
    for(int bit = 29; bit >= 0; --bit){
        int ans1, ans2;
        cout << "? " << num1 + (1 << bit) << " " << num2 << endl;
        cin >> ans1;
        cout << "? " << num1 << " " << num2 + (1 << bit) << endl;
        cin >> ans2;
        if(ans1 == 0) {
            if(state == 1) num1 += 1 << bit;
            else num2 += 1 << bit;
            continue;
        }
        if(state == 0){
            if(ans1 == -1){
                num1 += 1 << bit;
                num2 += 1 << bit;
            }
        } else if(state == 1){
            if(ans1 == 1){
                if(ans2 == 1){
                    num1 += 1 << bit;
                } else {
                    // nothing
                }
            } else {
                if(ans2 == 1){
                    num1 += 1 << bit;
                    num2 += 1 << bit;
                } else {
                    num1 += 1 << bit;
                    state = -1;
                }
            }
        } else {
            if(ans1 == 1){
                if(ans2 == 1){
                    num2 += 1 << bit;
                    state = 1;
                } else {
                    // nothing
                }
            } else {
                if(ans2 == 1){
                    num1 += 1 << bit;
                    num2 += 1 << bit;
                } else {
                    num2 += 1 << bit;
                }
            }
        }
    }
    cout << "! " << num1 << " " << num2 << endl;
}