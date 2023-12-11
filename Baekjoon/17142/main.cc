#include <bits/stdc++.h>

using namespace std;

int n, m;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};

int graph[51][51];
int vis[51][51];

vector<pair<int, int>> virus;
int virusCheck[11];

int roomCnt = 0;
int ans = 0x3f3f3f3f;

int bfs() {
    queue<pair<int, int>> q;
    memset(vis, -1, sizeof(vis));
    
    for(int i = 0; i < virus.size(); i++) {
        if(virusCheck[i]) {
            int vy = virus[i].first;
            int vx = virus[i].second;
            q.push({vy, vx});
            vis[vy][vx] = 0;
        }
    }
    
    int cnt = 0;
    int t = 0;
    
    while(!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;
        
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(vis[ny][nx] != -1) continue;
            if(graph[ny][nx] == 1) continue;
            
            q.push({ny, nx});
            vis[ny][nx] = vis[y][x] + 1;
            if(graph[ny][nx] == 0) {
                cnt++;
                t = vis[ny][nx];
            }
        }
    }
    if(cnt == roomCnt) return t;
    else return 0x3f3f3f3f;
}

void choice(int idx, int cnt) {
    if(cnt == m) {
        ans = min(ans, bfs());
        return;
    }
    if(idx == virus.size()) return;
    
    for(int i = idx+1; i < virus.size(); i++) {
        if(virusCheck[i]) continue;
        virusCheck[i] = true;
        choice(i, cnt+1);
        virusCheck[i] = false;
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> graph[i][j];
            if(graph[i][j] == 2) {
                virus.push_back({i, j});
            }
            else if(graph[i][j] == 0) {
                roomCnt++;
            }
        }
    }
    
    for(int i = 0; i < virus.size(); i++) {
        virusCheck[i] = true;
        choice(i, 1);
        virusCheck[i] = false;
    }
    
    if(ans == 0x3f3f3f3f) cout << -1;
    else cout << ans;
}