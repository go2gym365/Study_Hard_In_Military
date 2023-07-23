#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> vec(10, vector<int>(10, 0));
vector<vector<bool>> vis(10, vector<bool>(10, false));

int n, m;
int ans = -987654321;

int downRight(int y, int x) {
    return vec[y][x] + vec[y + 1][x] * 2 + vec[y + 1][x + 1];
}

int rightDown(int y, int x) {
    return vec[y][x] + vec[y][x + 1] * 2 + vec[y + 1][x + 1];
}

int upRight(int y, int x) {
    return vec[y][x] + vec[y - 1][x] * 2 + vec[y - 1][x + 1];
}

int rightUp(int y, int x) {
    return vec[y][x] + vec[y][x + 1] * 2 + vec[y - 1][x + 1];
}

void DFS(int y, int x, int sum) {
    if(x == m) {
        x = 0;
        y++;
    }
    if(y == n) {
        ans = max(ans, sum);
        return;
    }

    if(!vis[y][x]) {
        if(x + 1 < m && y + 1 < n && !vis[y + 1][x] && !vis[y + 1][x + 1]) {
            vis[y][x] = true;
            vis[y + 1][x] = true;
            vis[y + 1][x + 1] = true;
            int temp = sum + downRight(y, x);
            DFS(y, x + 1, temp);
            vis[y][x] = false;
            vis[y + 1][x] = false;
            vis[y + 1][x + 1] = false;
        }
        if(x + 1 < m && y + 1 < n && !vis[y][x + 1] && !vis[y + 1][x + 1]) {
            vis[y][x] = true;
            vis[y][x + 1] = true;
            vis[y + 1][x + 1] = true;
            int temp = sum + rightDown(y, x);
            DFS(y, x + 1, temp);
            vis[y][x] = false;
            vis[y][x + 1] = false;
            vis[y + 1][x + 1] = false;
        }
        if(x + 1 < m && y - 1 >= 0 && !vis[y - 1][x] && !vis[y - 1][x + 1]) {
            vis[y][x] = true;
            vis[y - 1][x] = true;
            vis[y - 1][x + 1] = true;
            int temp = sum + upRight(y, x);
            DFS(y, x + 1, temp);
            vis[y][x] = false;
            vis[y - 1][x] = false;
            vis[y - 1][x + 1] = false;
        }
        if(x + 1 < m && y - 1 >= 0 && !vis[y + 1][x] && !vis[y - 1][x + 1]) {
            vis[y][x] = true;
            vis[y][x + 1] = true;
            vis[y - 1][x + 1] = true;
            int temp = sum + rightUp(y, x);
            DFS(y, x + 1, temp);
            vis[y][x] = false;
            vis[y][x + 1] = false;
            vis[y - 1][x + 1] = false;
        }
    }
    DFS(y, x + 1, sum);
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> vec[i][j];
        }
    }

    DFS(0, 0, 0);

    cout << ans;
}