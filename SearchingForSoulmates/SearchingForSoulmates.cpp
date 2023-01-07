#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<pair<long long, int>> generateVector(long long num, bool start_or_end){
    int count = 0;
    vector<pair<long long, int>> vector;
    vector.push_back(make_pair(num, 0));
    while(num!=1){
        ++count;
        if(num%2 == 0) num/= 2;
        else if (start_or_end) num+=1;
        else num-=1;
        vector.push_back(make_pair(num, count));
    }
    return vector;
}

long long getMin(vector<pair<long long, int>> start, vector<pair<long long, int>> end){
    long long minimum = -1;
    for (pair p1:start){
        for (pair p2:end){
            if(p1.first > p2.first){
                break; //probably should be break
            } else {
                long long val = p1.second+p2.second+p2.first-p1.first;
                if(minimum==-1 || val < minimum){
                    minimum = val;
                }
            }
        }
    }
    return minimum;
}

int main(){
    int n;
    cin >> n;
    long long p1;
    long long p2;
    vector<pair<long long, int>> start;
    vector<pair<long long, int>> end;
    for (int c = 0; c < n; c++){
        cin >> p1 >> p2;
        start = generateVector(p1, true);
        end = generateVector(p2, false);
        cout << getMin(start, end) << endl;  
    }
    return 0;
}