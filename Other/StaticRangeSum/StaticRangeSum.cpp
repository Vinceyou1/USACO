#include <iostream>
using namespace std;

int arr[500000];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << "balls";
    int n, q;
    cin >> n >> q;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<q; i++){
        int l, r;
        cin>>l>>r;
        int total = 0;
        for(int i=l; i<r; i++){
            total+=arr[i];
        }
        cout << total << "\n";
    }
    return 0;
}