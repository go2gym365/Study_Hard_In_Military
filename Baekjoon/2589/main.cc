#include<bits/stdc++.h>

using namespace std;

vector<vector<char>> vec(51, vector<char> (51, ' '));
vector<vector<int>> length(51, vector<int> (51, 0));
vector<vector<bool>> vis(51, vector<bool> (51, false));

int n, m;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int ans = -98754321;

void reset() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            vis[i][j] = false;
            length[i][j] = 0;
        }
    }
}

void BFS(int yy, int xx) {
    queue<pair<int, int>> q;
    reset();
    q.push({yy, xx});

    vis[yy][xx] = true;

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;

        q.pop();

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(vis[ny][nx]) continue;
            if(vec[ny][nx] == 'W') continue;
            
            vis[ny][nx] = true;
            length[ny][nx] = length[y][x] + 1;

            q.push({ny, nx});
            ans = max(ans, length[ny][nx]);
        }
    }
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> vec[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(vec[i][j] == 'W') continue;
            BFS(i, j);
        }
    }

    cout << ans;
}