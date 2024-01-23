#include<bits/stdc++.h>

using namespace std;

string arr[101];
bool vis[101][101];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int n, m;

int bfs(int yy, int xx) {
    queue<pair<int, int>> q;
    vis[yy][xx] = true;
    q.push({yy, xx});
    
    int cnt = 0;
    
    char team = arr[yy][xx];
    
    while(!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;
        
        q.pop();
        
        cnt++;
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(vis[ny][nx]) continue;
            if(arr[ny][nx] != team) continue;
            
            q.push({ny, nx});
            vis[ny][nx] = true;
        }
    }
    
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        cin >> arr[i];
    }
    
    int bCnt = 0;
    int wCnt = 0;
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(vis[i][j]) continue;
        
            if(arr[i][j] == 'B') {
                bCnt += pow(bfs(i, j), 2);
            }
            else if(arr[i][j] == 'W') {
                wCnt += pow(bfs(i, j), 2);
            }
        }
    }
    
    cout << wCnt << ' ' << bCnt;
}