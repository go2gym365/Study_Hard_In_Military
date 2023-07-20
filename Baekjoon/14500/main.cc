#include<bits/stdc++.h>

using namespace std;

int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

vector<vector<int>> vec(501, vector<int>(501, 0));
vector<vector<bool>> vis(501, vector<bool>(501, false));

int DFS(int y, int x, int cnt) {
    if(cnt == 4) {
        return vec[y][x];
    }

    int sum = 0;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
        if(vis[ny][nx]) continue;
        vis[ny][nx] = true;
        sum = max(sum, vec[y][x] + DFS(ny, nx, cnt + 1));
        vis[ny][nx] = false;
    }

    return sum;
}

int fxxkshape(int y, int  x) {
    int ans = 0;
    
    //ㅗ
    if(x >= 1 && y >= 1 && x < m + 1)
        ans = max(ans, vec[y][x] + vec[y - 1][x] + vec[y][x - 1] + vec[y][x + 1]);
    //ㅏ
    if(x + 1 <= m && y + 1 <= n && y >= 1)
        ans = max(ans, vec[y][x] + vec[y - 1][x] + vec[y + 1][x] + vec[y][x + 1]);
    //ㅜ
    if(x + 1 <= m && y + 1 <= n && y >= 1)
        ans = max(ans, vec[y][x] + vec[y][x - 1] + vec[y][x + 1] + vec[y + 1][x]);
    //ㅓ
    if(x >= 1 && y >= 1 && y + 1 <= n)
        ans = max(ans, vec[y][x] + vec[y - 1][x] + vec[y][x - 1] + vec[y + 1][x]);

    return ans;
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> vec[i][j];
        }
    }

    int res = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            vis[i][j] = true;
            res = max(res, DFS(i, j, 1));
            res = max(res, fxxkshape(i, j));
            vis[i][j] = false;
        }
    }

    cout << res;
}