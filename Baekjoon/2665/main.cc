#include <bits/stdc++.h>

using namespace std;

int n;

int graph[51][51];
int vis[51][51];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void bfs() {
    queue<pair<int, int>> q;
    
    q.push({0, 0});
    vis[0][0] = 0;
    
    while(!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            
            if(graph[ny][nx]) {
                if(vis[ny][nx] > vis[y][x]) {
                    vis[ny][nx] = vis[y][x];
                    q.push({ny, nx});
                }
            }
            else {
                if(vis[ny][nx] > vis[y][x] + 1) {
                    vis[ny][nx] = vis[y][x] + 1;
                    q.push({ny, nx});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(vis, 0x3f3f3f3f, sizeof(vis));
    
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < n; j++) {
            graph[i][j] = str[j]-'0';
        }
    }
    
    bfs();
    
    cout << vis[n-1][n-1];
}