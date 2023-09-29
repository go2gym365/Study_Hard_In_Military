#include<bits/stdc++.h>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int n, m;
int vis[501][501];
vector<vector<int>> input(501, vector<int> (501, 0));
int dp[501][501];

int solve(int y, int x) {
    if(y == n - 1 && x == m - 1) return 1;
    int &ret = dp[y][x];
    if(dp[y][x] != -1) return ret;
    
    ret = 0;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
        if(input[y][x] <= input[ny][nx]) continue;
        ret += solve(ny, nx);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> input[i][j];
        }
    }

    cout << solve(0, 0);
}