#include<bits/stdc++.h>
using namespace std;
int n, m;
int pmax = 0, cnt = 0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

vector<vector<int>> paper(500, vector<int>(500, 0));
vector<vector<bool>> vis(500, vector<bool>(500, 0));

void BFS(int yy, int xx) {
    queue<pair<int, int>> q;
    int size = 0;
    q.push({yy, xx});
    vis[yy][xx] = true;

    while(!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;
        //vis[y][x] = true;
        q.pop();
        size++;

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= m || nx < 0 || ny >= n || ny < 0) continue;
            if (paper[ny][nx] == 0 || vis[ny][nx]) continue;
            vis[ny][nx] = true;
            q.push({ny, nx});
        }
    }
    cnt++;
    if(pmax < size) {
        pmax = size;
    }
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> paper[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(paper[i][j] == 1 && !vis[i][j]) 
                BFS(i, j);
        }
    }

    cout << cnt << " " << pmax;
}