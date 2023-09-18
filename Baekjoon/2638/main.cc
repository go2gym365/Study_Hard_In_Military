#include <bits/stdc++.h>

using namespace std;

int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

vector<vector<int>> cheese(101, vector<int>(101, 0));
bool vis[101][101];
bool meltCnt[101][101];
bool isAir[101][101]; //외부공기인지 체크

void isInsideAir() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    vis[0][0] = true;
    isAir[0][0] = true;

    while(!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;

        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if(cheese[ny][nx] == 1) continue;
            if(vis[ny][nx]) continue;
            q.push({ny, nx});
            vis[ny][nx] = true;
            isAir[ny][nx] = true;
        }
    }
}

void BFS(int yy, int xx) {
    queue<pair<int, int>> q;

    q.push({yy, xx});
    vis[yy][xx] = true;

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        int airCnt = 0;

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(cheese[ny][nx] == 0 && isAir[ny][nx]) 
                airCnt++;
            if(cheese[ny][nx] == 1 && !vis[ny][nx]) {
                q.push({ny, nx});
                vis[ny][nx] = true;
            }
        }
        if(airCnt >= 2) {
            meltCnt[y][x] = true;
        }
    }
}

void melt() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(meltCnt[i][j]) {
                cheese[i][j]--;
                meltCnt[i][j] = false;
            }
            vis[i][j] = false;
            isAir[i][j] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(meltCnt, false, sizeof(meltCnt));
    
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> cheese[i][j];
        }
    }

    int answer = 0;

    while (true) {
        isInsideAir();
        memset(vis, false, sizeof(vis));
        bool cheeseCheck = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(cheese[i][j] == 1 && !vis[i][j]) {
                    BFS(i, j);
                    cheeseCheck = true;
                }
            }
        }
        if(!cheeseCheck) break;
        else melt();
        answer++;
    }
    cout << answer;
}