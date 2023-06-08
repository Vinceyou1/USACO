#include <bits/stdc++.h>
using namespace std;

int main(){
    int **map = new int*[2001];
    int **vertex_prefix = new int*[2001];
    int **horiz_edge_prefix = new int*[2001];
    int **vert_edge_prefix = new int*[2001];
    for(int i = 0; i < 2001; i++){
        vertex_prefix[i] = new int[2001]{0};
        horiz_edge_prefix[i] = new int[2001]{0};
        vert_edge_prefix[i] = new int[2001]{0};
        map[i] = new int[2001]{0};
    }
    int N, M, Q;
    cin >> N >> M >> Q;
    for(int y = 1; y <= N; y++){
        for(int x = 1; x <= M; x++){
            char c;
            cin >> c;
            int num = c - '0';
            map[x][y] = num;
            vertex_prefix[x][y] = num + vertex_prefix[x][y-1] + vertex_prefix[x-1][y] - vertex_prefix[x-1][y-1];
            horiz_edge_prefix[x][y] = horiz_edge_prefix[x-1][y] + horiz_edge_prefix[x][y-1] - horiz_edge_prefix[x-1][y-1];
            vert_edge_prefix[x][y] = vert_edge_prefix[x-1][y] + vert_edge_prefix[x][y-1] - vert_edge_prefix[x-1][y-1];
            if(num && map[x-1][y]) horiz_edge_prefix[x][y]++;
            if(num && map[x][y-1]) vert_edge_prefix[x][y]++;
        }
    }
    // for(int y = 0; y < 5; y++){
    //     for(int x = 0; x < 5; x++){
    //         cout << vert_edge_prefix[x][y];
    //     }
    //     cout << endl;
    // }
    while(Q--){
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        // cout << "Vertexes:" << vertex_prefix[x2][y2] - vertex_prefix[x1-1][y2] - vertex_prefix[x2][y1-1] + vertex_prefix[x1-1][y1-1];
        // cout << "Horizontal Edges:" << horiz_edge_prefix[x2][y2] - horiz_edge_prefix[x1][y2] - horiz_edge_prefix[x2][y1-1] + horiz_edge_prefix[x1][y1-1];
        // cout << "Vertical Edges:" << vert_edge_prefix[x2][y2] - vert_edge_prefix[x1-1][y2] - vert_edge_prefix[x2][y1] + vert_edge_prefix[x1-1][y1];
        cout << vertex_prefix[x2][y2] - vertex_prefix[x1-1][y2] - vertex_prefix[x2][y1-1] + vertex_prefix[x1-1][y1-1] -
            (horiz_edge_prefix[x2][y2] - horiz_edge_prefix[x1][y2] - horiz_edge_prefix[x2][y1-1] + horiz_edge_prefix[x1][y1-1]) - 
            (vert_edge_prefix[x2][y2] - vert_edge_prefix[x1-1][y2] - vert_edge_prefix[x2][y1] + vert_edge_prefix[x1-1][y1]) << "\n";
    }
}