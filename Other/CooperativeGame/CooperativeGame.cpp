#include <bits/stdc++.h>
using namespace std;

int main(){
    int locations = -1;
    string temp;
    while(locations != 2){
        cout << "next 0 1" << endl;
        cout.flush();
        getline(cin, temp);
        cout << "next 1" << endl;
        cout.flush();
        cin >> locations;
        getline(cin, temp);
    }
    while(locations != 1){
        cout << "next 0 1 2 3 4 5 6 7 8 9" << endl;
        cout.flush();
        cin >> locations;
        getline(cin, temp);
    }
    cout << "done" << endl;
    cout.flush();
}