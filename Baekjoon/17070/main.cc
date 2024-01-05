#include<bits/stdc++.h>

using namespace std;

int dx[3] = {0, 1, 1};
int dy[3] = {1, 1, 0};

int n;
const int INF = 0x3f3f3f3f;

int graph[17][17];
int dp[17][17][3];

int solve(int y, int x, int type) {
    if(y == n-1 && x == n-1) return 1;
    else if(y < 0 || x < 0 || x >= n || y >= n) return 0;

    int &ret = dp[y][x][type];
    if(ret != -1) return ret;
    
    ret = 0;
    
    for(int i = 0; i < 3; i++) {
        if(type == 0 && i == 2) continue;
        else if(type == 2 && i == 0) continue; 
        
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(graph[ny][nx] == 1) continue;
        if(i == 1 && (graph[ny-1][nx] || graph[ny][nx-1])) continue;
        
        ret += solve(ny, nx, i);
    }
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));
    
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    
    cout << solve(0, 1, 2);
}