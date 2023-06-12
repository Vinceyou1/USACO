#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, t;
    cin >> n >> t;
    vector<int> books(n);
    while(n--){
        cin >> books[books.size()-1-n];
    }
    int left = 0;
    int right = 0;
    int time = books[0];
    int max_books = 0;
    while(right < books.size()){
        if(time <= t){
            max_books = max(right - left + 1, max_books);
            right++;
            if(right < books.size()) time += books[right];
        }
        else{
            left++;
            time -= books[left - 1];
        }
    }
    cout << max_books;
}