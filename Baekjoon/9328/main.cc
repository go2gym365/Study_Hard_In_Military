#include <bits/stdc++.h>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int h, w;

char room[102][102];
bool vis[102][102];
bool key[26];

int bfs() {
    queue<pair<int, int>> q;
    queue<pair<int, int>> keyDir[26];
    
    int ans = 0;
    
    q.push({0, 0});
    vis[0][0] = true;
    
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        
        q.pop();
        
        if(room[y][x] == '$') ans++;
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx > w+1 || ny > h+1) continue;
            if(room[ny][nx] == '*') continue;
            if(vis[ny][nx]) continue;
            
            if(room[ny][nx] >= 'A' && room[ny][nx] <= 'Z') {
                int keyNum = room[ny][nx]-'A';
                if(key[keyNum]) {
                    vis[ny][nx] = true;
                    q.push({ny, nx});
                }
                else {
                    keyDir[keyNum].push({ny, nx});
                }
            }
            else if(room[ny][nx] >= 'a' && room[ny][nx] <= 'z') {
                int keyNum = room[ny][nx]-'a';
                
                vis[ny][nx] = true;
                key[keyNum] = true;
                q.push({ny, nx});
                
                while(!keyDir[keyNum].empty()) {
                    q.push(keyDir[keyNum].front());
                    keyDir[keyNum].pop();
                }
            }
            else {
                vis[ny][nx] = true;
                q.push({ny, nx});
            }
        }
    }
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    
    while(t--) {
        memset(room, '.', sizeof(room));
        memset(vis, false, sizeof(vis));
        memset(key, false, sizeof(key));

        cin >> h >> w;
        
        for(int i = 1; i <= h; i++) {
            for(int j = 1; j <= w; j++) {
                cin >> room[i][j];
            }
        }
        
        string k;
        cin >> k;
        
        if(k != "0") {
            for(int i = 0; i < k.size(); i++) {
                key[k[i]-'a'] = true;
            }
        }
        
        cout << bfs() << "\n";
    }
}