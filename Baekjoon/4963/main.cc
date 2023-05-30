#include<bits/stdc++.h>
using namespace std;

int w, h, cnt = 0;
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

vector<vector<int>> island(51, vector<int>(51, 0));
vector<vector<bool>> vis(51, vector<bool>(51, false));

void BFS(int yy, int xx) {
    queue<pair<int, int>> q;
    q.push({yy, xx});

    while(!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;
        cnt++;
        vis[y][x] = true;
        q.pop();

        for(int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= w || nx < 0 || ny >= h || ny < 0) continue;
            if(vis[ny][nx] || island[ny][nx] == 0) continue;
            q.push({ny, nx});
            vis[ny][nx] = true;
        }
    }
}

int main() {
    while(1) {
        cin >> w >> h;
        if(w == 0 && h == 0) break;

        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                cin >> island[i][j];
            }
        }
        
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(island[i][j] == 1 && !vis[i][j]) {
                    BFS(i, j);
                }
            }
        }
        cout << cnt << "\n";
        cnt = 0;
    }
}