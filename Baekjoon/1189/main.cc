#include <bits/stdc++.h>

using namespace std;

int r, c, k;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

char graph[6][6];
bool vis[6][6];

int DFS(int yy, int xx, int cnt) {
    if(yy == 0 && xx == c-1) {
        if(cnt == k) {
            return 1;
        }
        else return 0;
    }
    
    int ret = 0;
    
    for(int i = 0; i < 4; i++) {
        int nx = xx + dx[i];
        int ny = yy + dy[i];
        
        if(nx < 0 || ny < 0 || nx >= c || ny >= r) continue;
        if(vis[ny][nx]) continue;
        if(graph[ny][nx] == 'T') continue;
        
        vis[ny][nx] = true;
        ret += DFS(ny, nx, cnt+1);
        vis[ny][nx] = false;
    }
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> r >> c >> k;
    
    for(int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> graph[i][j];
        }
    }
    
    vis[r-1][0] = true;
    cout << DFS(r-1, 0, 1);
}