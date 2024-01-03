#include <bits/stdc++.h>
using namespace std;

int grid[250][250];
int component[250][250];
int n;

int ff_one(int x, int y, int num, int comp){
    if(x < 0 || x >= n || y < 0 || y >= n) return 0;
    if(component[x][y]) return 0;
    if(grid[x][y] != num) return 0;
    component[x][y] = comp;
    return 1 + ff_one(x - 1, y, num, comp) + ff_one(x + 1, y, num, comp) + ff_one(x, y - 1, num, comp) + ff_one(x, y + 1, num, comp);
}

int get_size(int num1, int num2, int node, vector<vector<int>> &neighbors, vector<bool> &node_visited, vector<int> &component_sizes, vector<int> &component_vals){
    int ans = 0;
    node_visited[node] = true;
    for(int i: neighbors[node]){
        if(!node_visited[i] && (component_vals[i] == num1 || component_vals[i] == num2))
            ans += get_size(num1, num2, i, neighbors, node_visited, component_sizes, component_vals);
    }
    return ans + component_sizes[node];
}

int main(){
    freopen("multimoo.in", "r", stdin);
    cin >> n;
    set<int> distinct;
    for(int row = 0; row < n; ++row){
        for(int col = 0; col < n; ++col){
            cin >> grid[row][col];
            distinct.insert(grid[row][col]);
        }
    }

    int ans1 = 0;
    int component_num = 1;
    vector<int> component_vals;
    vector<int> component_sizes;
    for(int row = 0; row < n; ++row){
        for(int col = 0; col < n; ++col){
            if(component[row][col]) continue;
            int size = ff_one(row, col, grid[row][col], component_num);
            component_num++;
            component_sizes.push_back(size);
            component_vals.push_back(grid[row][col]);
            ans1 = max(size, ans1);
        }
    }
    vector<vector<int>> neighbors(component_num - 1); // for each component, what are its neighbors?
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(i < n - 1 && component[i][j] != component[i + 1][j]){
                neighbors[component[i][j] - 1].push_back(component[i + 1][j] - 1);
                neighbors[component[i + 1][j] - 1].push_back(component[i][j] - 1);
            }
            if(j < n - 1 && component[i][j] != component[i][j + 1]){
                neighbors[component[i][j + 1] - 1].push_back(component[i][j] - 1);
                neighbors[component[i][j] - 1].push_back(component[i][j + 1] - 1);
            }
        }
    }
    // vector<vector<bool>> edge_taken(component_num - 1);
    // for(int i = 0; i < neighbors.size(); ++i){
    //     while(edge_taken[i].size() < neighbors[i].size()) edge_taken[i].push_back(false);
    // }
    int ans2 = 0;
    vector<bool> node_visited(component_num - 1);
    for(int i = 0; i < component_sizes.size(); ++i){
        for(int j: neighbors[i]){
            fill(node_visited.begin(), node_visited.end(), false);
            ans2 = max(ans2, get_size(component_vals[i], component_vals[j], i, neighbors, node_visited, component_sizes, component_vals));
        }
        
    }

    freopen("multimoo.out", "w", stdout);
    cout << ans1 << endl << ans2;
}