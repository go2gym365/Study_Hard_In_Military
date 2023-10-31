#include <iostream>

using namespace std;

int n, m;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int input[51][51];
bool vis[51][51];

int ans = 1;

void dfs(int x, int y, int d) {
    for(int i = 0; i < 4; i++) {
        int nd = (d + 3 - i) % 4;
        int nx = x + dx[nd];
        int ny = y + dy[nd];
        
        if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
        if(input[ny][nx] == 1) continue;
        if(vis[ny][nx]) continue;
        
        vis[ny][nx] = true;
        ans++;
        dfs(nx, ny, nd);
    }
    
    int nd = d > 1 ? d - 2 : d + 2;
    int nx = x + dx[nd];
    int ny = y + dy[nd];
    
    if(nx >= 0 && nx < m && ny >= 0 && ny < n) {
        if(input[ny][nx] == 0) {
            dfs(nx, ny, d);
        }
        else {
            cout << ans;
            exit(0);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int ry, rx, rd;
    
    cin >> n >> m;
    cin >> ry >> rx >> rd;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> input[i][j];
            vis[i][j] = false;
        }
    }
    
    vis[ry][rx] = true;
    
    dfs(rx, ry, rd);
}
