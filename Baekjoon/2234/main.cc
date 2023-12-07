#include <bits/stdc++.h>

using namespace std;

int n, m;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int graph[51][51];
bool vis[51][51];

int roomCnt = 0;
int maxRoom = 0;
int breakMaxRoomCnt = 0;

int BFS(int yy, int xx) {
    queue<pair<int, int>> q;
    
    int cnt = 0;
    q.push({yy, xx});
    vis[yy][xx] = true;
    
    while(!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        cnt++;
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if(vis[ny][nx]) continue;
            
            if((graph[y][x] & (1 << i))) continue;
            q.push({ny, nx});
            vis[ny][nx] = true;
        }
    }
    
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> m >> n;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(vis[i][j]) continue;
            maxRoom = max(maxRoom, BFS(i, j));
            roomCnt++;
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 1; k <= 8; k <<= 1) {
                if(graph[i][j] & k) {
                    memset(vis, false, sizeof(vis));
                    graph[i][j] -= k;
                    breakMaxRoomCnt = max(breakMaxRoomCnt, BFS(i, j));
                    graph[i][j] += k;
                }
            }
        }
    }
    
    cout << roomCnt << '\n';
    cout << maxRoom << '\n';
    cout << breakMaxRoomCnt << '\n';
}