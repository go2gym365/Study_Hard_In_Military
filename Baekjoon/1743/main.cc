#include<bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

vector<vector<int>> route(102, vector<int>(102, 0));
vector<vector<bool>> vis(102, vector<bool>(102, false));
int N, M, K;
int maxs = 0, ss = 0;

void DFS(int y, int x) {
    ss++;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= M || nx < 0 || ny >= N || ny < 0) continue;
        if(vis[ny][nx] || route[ny][nx] == 0) continue;
        vis[ny][nx] = true;
        DFS(ny, nx);
    }
}

int main() {
    cin >> N >> M >> K;
    for(int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        route[a-1][b-1] = 1;
    }

    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= M; j++) {
            if(route[i][j] == 1 && !vis[i][j]) {
                ss = 0;
                vis[i][j] = true;
                DFS(i, j);
                if(ss > maxs) {
                    maxs = ss;
                }  
            }
        }
    }

    cout << maxs;
}