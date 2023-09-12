#include<bits/stdc++.h>

using namespace std;

vector<string> vec(1001, "");
vector<vector<int>> vis(1001, vector<int>(1001, 0));


int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

 int n, m;
 int fy = 0; int fx = 0;
 int sy; int sx;
 int staTofi = 0;
 int fiToHo = 0;

int fishToHome(int yy, int xx) {
    queue<pair<int, int>> q;
    vis[yy][xx] = 0;

    q.push({yy, xx});

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;

        q.pop();

        if(vec[y][x] == 'H') {
            return vis[y][x];
        }

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(vec[ny][nx] == 'D') continue;
            if(vis[ny][nx] != 0) continue;
            if(ny == fy && nx == fx) continue;
            
            q.push({ny, nx});
            vis[ny][nx] = vis[y][x] + 1;
        }
    }
    return -1;
}

int startToFish(int yy, int xx) {
    queue<pair<int, int>> q;
    int check = false;
    int count = 0x3f3f3f3f;

    q.push({yy, xx});

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;

        q.pop();

        if(vec[y][x] == 'F') {
            check = true;
            if(count > vis[y][x]) {
                count = vis[y][x];
                fx = x;
                fy = y;
            }
        }

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(vec[ny][nx] == 'D') continue;
            if(vis[ny][nx] != 0) continue;
            if(ny == sy && nx == sx) continue;
            
            q.push({ny, nx});
            vis[ny][nx] = vis[y][x] + 1;
        }
    }
    if(check) return count;
    else return -1;
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    for(int i = 0; i < n; i++) {
        bool pen = false;
        for(int j = 0; j < m; j++) {
            if(vec[i][j] == 'S') {
                pen = true;
                staTofi = startToFish(i, j);
                if(staTofi == -1) {
                    cout << -1;
                    return 0;
                }
                sy = i; sx = j;
            }
        }
        if(pen) break;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i <= fy && j <= fx) continue;
            if(vis[i][j] == 0) continue;
            vis[i][j] = 0;
        }
    }

    fiToHo = fishToHome(fy, fx);
    if(fiToHo == -1) {
        cout << -1;
        return -1;
    }
    else {
        cout << staTofi + fiToHo;
    }
}