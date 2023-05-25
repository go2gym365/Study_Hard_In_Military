#include<bits/stdc++.h>
using namespace std;

int N, M, K;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void DFS(int y, int x, vector<vector<int>>& m, vector<vector<bool>>& vis) {
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= M || nx < 0 || ny >= N || ny < 0) continue;
        if(vis[ny][nx] || m[ny][nx] == 0) continue;   
        vis[ny][nx] = true;
        DFS(ny, nx, m, vis);
    }
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        vector<vector<int>> m(50, vector<int>(50, 0));
        vector<vector<bool>> vis(50, vector<bool>(50, false));
        cin >> M >> N >> K;
        while(K--) {
            int x, y;
            cin >> x >> y;
            m[y][x] = 1;
        }
        int ans = 0;
        for(int i = 0; i < N; i++) {
            for(int j =0; j < M; j++) {
                if(!vis[i][j] && m[i][j] == 1) {
                    
                    vis[i][j] = true;
                    DFS(i, j, m, vis);
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }
}