#include <bits/stdc++.h>

using namespace std;

int r, c;
int sy, sx;

int thingCnt=0;

char room[51][51];
int vis[51][51][1 << 5];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int bfs() {
    queue<pair<pair<int, int>, pair<int, int>>> q;
    
    q.push({{sy, sx}, {0, 0}});
    vis[sy][sx][0] = true;
    
    while(!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int cost = q.front().second.first;
        int thing = q.front().second.second;
        
        q.pop();
        
        if(room[y][x] == 'E') {
            if(thing == thingCnt) {
                return cost;
            }
        }
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= c || ny < 0 || ny >= r) continue;
            if(room[ny][nx] == '#') continue;
            
            if(room[ny][nx] >= '0' && room[ny][nx] <= '4') {
                int newThingState = thing | (1 << (room[ny][nx]-'0'));
                
                if(vis[ny][nx][newThingState]) continue;
                
                q.push({{ny, nx}, {cost+1, newThingState}});
                vis[ny][nx][newThingState] = true;
            }
            else {
                if(vis[ny][nx][thing]) continue;
                
                q.push({{ny, nx}, {cost+1, thing}});
                vis[ny][nx][thing] = true;
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> c >> r;
    
    int cnt = 0;
    
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> room[i][j];
            if(room[i][j] == 'S') {
                sy = i;
                sx = j;
                room[i][j] == '.';
            }
            else if(room[i][j] == 'X') {
                room[i][j] = cnt+'0';
                thingCnt = thingCnt | (1 << cnt);
                cnt++;
            }
        }
    }
    
    cout << bfs();
}