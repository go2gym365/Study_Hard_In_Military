#include <bits/stdc++.h>

using namespace std;

int n, m;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int graph[101][101];
bool vis[101][101];
//해당 높이가 가장 높은 산봉우리인지 확인
bool isPeak;

void BFS(int yy, int xx) {
    queue<pair<int, int>> q;
    
    q.push({yy, xx});
    vis[yy][xx] = true;
    
    while(!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        
        for(int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            //처음 BFS들어왔을 때 높이보다 높은게 있으면
            //이 높이는 산봉우리가 아니기때문에 카운트 X
            if(graph[yy][xx] < graph[ny][nx]) isPeak = false;
            if(vis[ny][nx]) continue;
            if(graph[yy][xx] != graph[ny][nx]) continue;
            q.push({ny, nx});
            vis[ny][nx] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }
    
    int cnt = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(vis[i][j]) continue;
            if(!graph[i][j]) continue;
            isPeak = true;
            BFS(i, j);
            if(isPeak) cnt++;
        }
    }
    
    cout << cnt;
}