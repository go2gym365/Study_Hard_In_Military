#include <bits/stdc++.h>
 
using namespace std;
 
int n, m;
bool vis[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
 
int main() {
    int n, m;
    
    cin >> n >> m;
    
    int y = 0;
    int x = 0;
    vis[0][0] = true;
    int dir = 0;
    int cnt = 0;
    
    while(true) {
        x += dx[dir];
        y += dy[dir];
        
        if(y < 0 || y >= n || x < 0 || x >= m || vis[y][x]) {
            x -= dx[dir];
            y -= dy[dir];
            dir = (dir+1)%4;
            if(vis[y+dy[dir]][x+dx[dir]]) break;
            cnt++;
        }
        
        vis[y][x] = true;
    }
    cout << cnt;
}