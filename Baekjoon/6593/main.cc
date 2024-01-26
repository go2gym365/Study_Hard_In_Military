#include<bits/stdc++.h>

using namespace std;

int l, r, c;
int sx, sy, sz;

char building[31][31][31];
bool vis[31][31][31];

int dz[6] = {0, 0, 0, 0, 1, -1};
int dx[6] = {-1, 0, 1, 0, 0, 0};
int dy[6] = {0, -1, 0, 1, 0, 0};

int bfs() {
    queue<pair<pair<int, int>, pair<int, int>>> q;
    
    q.push({{0, sz}, {sy, sx}});
    vis[sz][sy][sx] = true;
    
    while(!q.empty()) {
        int cost = q.front().first.first;
        int z = q.front().first.second;
        int y = q.front().second.first;
        int x = q.front().second.second;
        
        q.pop();
        
        if(building[z][y][x] == 'E') {
            return cost;
        }
        
        for(int i = 0; i < 6; i++) {
            int nz = z + dz[i];
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(nz < 0 || nz >= l) continue;
            if(nx < 0 || nx >= c || ny < 0 || ny >= r) continue;
            if(vis[nz][ny][nx]) continue;
            if(building[nz][ny][nx] == '#') continue;
            
            q.push({{cost+1, nz}, {ny, nx}});
            vis[nz][ny][nx] = true;
        }
    }
    
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int tl = 0;
    int tr = 0;
    int tc = 0;
    
    while(1) {
        cin >> l >> r >> c;
        if(l == 0 && r == 0 && c == 0) break;
        
        for(int i = 0; i < tl; i++) {
            for(int j = 0; j < tr; j++) {
                for(int k = 0; k < tc; k++) {
                    vis[i][j][k] = false;
                }
            }
        }
        tl = l; tr = r; tc = c;
        
        for(int i = 0; i < l; i++) {
            for(int j = 0; j < r; j++) {
                string str;
                cin >> str;
                for(int k = 0; k < c; k++) {
                    building[i][j][k] = str[k];
                    if(str[k] == 'S') {
                        sz = i;
                        sy = j;
                        sx = k;
                    }
                }
            }
        }
        
        int ret = bfs();
        
        if(ret == -1) {
            cout << "Trapped!" << '\n';
        }
        else {
            cout << "Escaped in " << ret << " minute(s)." << '\n';
        }
    }
}