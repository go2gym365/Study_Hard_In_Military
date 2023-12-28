#include <bits/stdc++.h>

using namespace std;

char graph[51][51];
bool vis[51][51][1<<6];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int r, c;
int sy, sx;

void bfs() {
    queue<pair<pair<int, int>, pair<int, int>>> q;
    
    q.push({{sy, sx}, {0, 0}});
    
    while(!q.empty()) {
        int x = q.front().first.second;
        int y = q.front().first.first;
        int curCnt = q.front().second.first;
        int keyInfo = q.front().second.second;
        
        if(graph[y][x] == '1') {
            cout << curCnt;
            return;
        }
        
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= c || ny < 0 || ny >= r) continue;
            if(graph[ny][nx] == '#')continue;
            
            
            // 문
            if(graph[ny][nx] >= 'A' && graph[ny][nx] <= 'F') {
                //문 비트로 변환
                int roomNum = graph[ny][nx] - 'A';
                //문이랑 열쇠랑 대조
                bool check = keyInfo & (1 << roomNum);
                if(!check || vis[ny][nx][keyInfo]) continue;
                
                vis[ny][nx][keyInfo] = true;
                q.push({{ny, nx}, {curCnt+1, keyInfo}});
            }
            //열쇠
            else if(graph[ny][nx] >= 'a' && graph[ny][nx] <= 'f') {
                //열쇠 모은거에 지금 열쇠 합치기
                int newKeyInfo = keyInfo | (1 << (graph[ny][nx]-'a'));
                //이 열쇠 방문했었으면 안가기
                if(vis[ny][nx][newKeyInfo]) continue;
                
                q.push({{ny, nx}, {curCnt+1, newKeyInfo}});
                vis[ny][nx][newKeyInfo] = true;
            }
            else {
                if(vis[ny][nx][keyInfo]) continue;
                q.push({{ny, nx}, {curCnt+1, keyInfo}});
                vis[ny][nx][keyInfo] = true;
            }
        }
    }
    cout << -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> r >> c;
    
    for(int i = 0 ; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> graph[i][j];
            if(graph[i][j] == '0') {
                sy = i;
                sx = j;
            }
        }
    }
    
    bfs();
}