#include<bits/stdc++.h>

using namespace std;

int n;
int maxRain = 0;
int minRain = 0x3f3f3f3f;
int rainCnt = 0;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};

int graph[101][101];
bool vis[101][101];

void BFS(int yy, int xx, int limit) {
    queue<pair<int, int>> q;

    q.push({yy, xx});
    vis[yy][xx] = true;
    
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
               
            if (ny >= n || nx >= n || ny < 0 || nx < 0) continue;
            if (graph[ny][nx] <= limit) continue;
            if (vis[ny][nx]) continue;
            
            vis[ny][nx] = true;
            q.push({ny, nx});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n;

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
            if(maxRain < graph[i][j]) {
                maxRain = graph[i][j];
            }
            if(minRain > graph[i][j]) {
                minRain = graph[i][j];
            }
        }
    }
    
    for(int k = 0; k <= maxRain; k++) {
        memset(vis, false, sizeof(vis));
        int cnt = 0;
        
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(vis[i][j]) continue;
                if(graph[i][j] <= k) continue;
                BFS(i, j, k);
                cnt++;
            }
        }
        rainCnt = max(rainCnt, cnt);
    }
    
    cout << rainCnt;
}
