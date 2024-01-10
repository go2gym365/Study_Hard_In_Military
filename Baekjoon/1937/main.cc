#include<bits/stdc++.h>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int n;

int bamboo[501][501];
bool vis[501][501];
int dp[501][501];

int dfs(int y, int x) {
    int &ret = dp[y][x];
    if(ret != -1) return ret;
    
    ret = 1;
    
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if(vis[ny][nx]) continue;
        if(bamboo[ny][nx] <= bamboo[y][x]) continue;
        
        vis[ny][nx] = true;
        ret = max(ret, dfs(ny, nx)+1);
        vis[ny][nx] = false;
    }
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
    memset(dp, -1, sizeof(dp));
    
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> bamboo[i][j];
        }
    }
    
    int ans = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            vis[i][j] = true;
            ans = max(ans, dfs(i, j));
            vis[i][j] = false;
        }
    }
    
    cout << ans;
}