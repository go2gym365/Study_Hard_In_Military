#include <bits/stdc++.h>

using namespace std;

int graph[101][101];
bool vis[101][101];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int n, m, k;

int bfs(int yy, int xx) {
    queue<pair<int, int>> q;
    
    int cnt = 0;
    
    q.push({yy, xx});
    vis[yy][xx] = true;
    
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        
        q.pop();
        cnt++;
        
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(vis[ny][nx] == true) continue;
            
            q.push({ny, nx});
            vis[ny][nx] = true;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n >> m >> k;
    
    for(int i = 0; i < k; i++) {
        int x1, y1;
        int x2, y2;
        
        cin >> x1 >> y1 >> x2 >> y2;
        
        for(int i = y1; i < y2; i++) {
            for(int j = x1; j < x2; j++) {
                vis[i][j] = true;
            }
        }
    }
    
    priority_queue<int> pq;
    
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(vis[i][j]) continue;
            int area = bfs(i, j);
            
            pq.push(-area);
        }
    }
    
    cout << pq.size() << "\n";
    
    while(!pq.empty()) {
        cout << -pq.top() << ' ';
        pq.pop();
    }
    
}