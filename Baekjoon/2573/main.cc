#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> v(301, vector<int>(301, 0));
vector<vector<int>> cntv(301, vector<int>(301, 0));
vector<vector<bool>> vis(301, vector<bool>(301, false));

int n, m;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool isIce() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v[i][j] > 0) return true;
        }
    }
    return false;
}

void melt_cnt(int y, int x) {
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
        if(v[ny][nx] <= 0) cntv[y][x]++;
    }
}

void melt() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            v[i][j] = v[i][j] - cntv[i][j];
        }
    }
}

void DFS(int yy, int xx) {
    int cnt_0 = 0;

    for(int i = 0; i < 4; i++) {
        int nx = xx + dx[i];
        int ny = yy + dy[i];

        if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
        if(v[ny][nx] <= 0 || vis[ny][nx]) continue;
        vis[ny][nx] == true;
        DFS(ny, nx);
    }
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> v[i][j];
            if(v[i][j] != 0) vis[i][j] = true;
        }
    }

    int year = 0;
    
    while(1) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                vis[i][j] = 0;
                cntv[i][j] = 0;
            }
        }

        if(isIce() == false) {
            cout << "0";
            break;
        }

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(v[i][j] > 0 && !vis[i][j]) {
                    cnt++;
                    vis[i][j] = 1;
                    DFS(i, j);
                }
            }
        }

        if(cnt > 1) {
            cout << year;
            break;
        }
        year++;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(v[i][j] > 0) melt_cnt(i, j);
            }
        }

        melt();
    }
}