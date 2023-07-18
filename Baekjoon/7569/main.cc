#include<bits/stdc++.h>

using namespace std;

int n, m, h;
int cnt = 0;

int dx[6] = {-1, 0, 1, 0, 0, 0};
int dy[6] = {0, -1, 0, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

int tomato[101][101][101] = {0, };
bool vis[101][101][101] = {false, };

queue<pair<int, pair<int, int>>> q;

void BFS() {
    while(1) {
        
    }
    while(!q.empty()) {
        queue<pair<int, pair<int, int>>> future;    
        int z = q.front().first;
        int y = q.front().second.first;
        int x = q.front().second.second;
            
        q.pop();

        for(int i = 0; i < 6; i++) {
            int nz = z + dz[i];
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
            if(vis[nz][ny][nx]) continue;
            if(tomato[nz][ny][nx] == -1) continue;

            future.push({nz, {ny, nx}});
            vis[nz][ny][nx] = true;
        }

        if(future.empty()) {
            for(int k = 0; k < h; k++) {
                for(int i = 0; i < m; i++) {
                    for(int j = 0; j < n; j++) {
                        if(tomato[k][i][j] == 0 && !vis[k][i][j]) {
                            cout << -1;
                            return;
                        }
                    }
                }
            }
            cout << cnt;
            return;
        }
        q = future;
        cnt++;
    }
}

int main() {
    cin >> n >> m >> h;

    int t = 0;

    for(int k = 0; k < h; k++) {
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                cin >> tomato[k][i][j];
            }
        }
    }

    for(int k = 0; k < h; k++) {
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(tomato[k][i][j] == 1) {
                    q.push({k, {i, j}});
                    vis[k][i][j] = true;
                }
            }
        }
    }

    BFS();
}