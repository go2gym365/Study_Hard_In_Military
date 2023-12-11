#include <bits/stdc++.h>

using namespace std;

int graph[51][51];
bool vis[51][51];

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int w, h;

void bfs(int y, int x) {
    queue<pair<int, int>> q;
    
    q.push({y, x});
    vis[y][x] = true;
    
    while(!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;
        
        q.pop();
        
        for(int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
            if(vis[ny][nx]) continue;
            if(graph[ny][nx] == 0) continue;
            
            q.push({ny, nx});
            vis[ny][nx] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    while(true) {
        memset(graph, 0, sizeof(graph));
        memset(vis, false, sizeof(vis));
        
        int cnt = 0;
        
        cin >> w >> h;
        if(w == 0 && h == 0) break;
        
        for(int i =0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                cin >> graph[i][j];
            }
        }
        
        for(int i =0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(vis[i][j]) continue;
                if(graph[i][j] == 0) continue;
                
                bfs(i, j);
                cnt++;
            }
        }
        
        cout << cnt << "\n";
    }
}