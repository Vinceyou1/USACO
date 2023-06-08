#include <bits/stdc++.h>
using namespace std;

bool y_cmp(pair<int, int> &a, pair<int, int> &b){
    return a.second < b.second;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> coordinates;
    vector<array<int, 2501>> grid(2501);
    vector<array<int, 2501>> prefix_grid(2501);
    for(int c = 0; c < n; c++){
        int x, y;
        cin >> x >> y;
        coordinates.push_back(make_pair(x, y));
    }
    sort(coordinates.begin(), coordinates.end());
    map<int, int> reduced_x;
    for(int i = 0; i < n; i++){
        reduced_x[coordinates.at(i).first] = i + 1;
    }
    sort(coordinates.begin(), coordinates.end(), y_cmp);
    map<int, int> reduced_y;
    for(int i = 0; i < n; i++){
        reduced_y[coordinates.at(i).second] = i + 1;
    }
    for(int i = 0; i < n; i++){
        coordinates.at(i) = make_pair(reduced_x[coordinates.at(i).first], reduced_y[coordinates.at(i).second]);
        grid[coordinates.at(i).first][coordinates.at(i).second] = 1;
    }
    for(int x = 1; x < 2501; x++){
        for(int y = 1; y < 2501; y++){
            prefix_grid[x][y] = grid[x][y] + prefix_grid[x-1][y] + prefix_grid[x][y-1] - prefix_grid[x-1][y-1];
        }
    }
    // for(int i = 0; i < 5; i++){
    //     for(int j = 0; j < 5; j++){
    //         cout << grid[j][i] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for(int i = 0; i < 5; i++){
    //     for(int j = 0; j < 5; j++){
    //         cout << prefix_grid[j][i] << " ";
    //     }
    //     cout << endl;
    // }
    long long fences = 0;
    // Iterating through each pair of coordinates
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int max_x = max(coordinates.at(i).first, coordinates.at(j).first); // 3
            int min_x = min(coordinates.at(i).first, coordinates.at(j).first); // 2
            int max_y = max(coordinates.at(i).second, coordinates.at(j).second); // 3
            int min_y = min(coordinates.at(i).second, coordinates.at(j).second); // 1
            int left = prefix_grid[min_x-1][max_y] - prefix_grid[min_x-1][min_y-1];
            int right = prefix_grid[2500][max_y] - prefix_grid[max_x][max_y] - prefix_grid[2500][min_y] + prefix_grid[max_x][min_y];
            fences += (left + 1) * (right + 1);
        }
    }
    fences += n + 1;
    cout << fences;
    return 0;
}