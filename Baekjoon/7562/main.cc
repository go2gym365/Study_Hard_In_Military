#include<bits/stdc++.h>

using namespace std;

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};


int l, movex, movey;

vector<vector<int>>v(301, vector<int>(301, 0));
vector<vector<bool>>vis(301, vector<bool>(301, false));

void BFS(int xx, int yy) {
    queue<pair<int, int>> q;
    q.push({yy, xx});
    vis[yy][xx] = true;

    while(!q.empty()){
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        
        if(x == movex && y == movey) return;

        
        for(int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= l || nx < 0 || ny >= l || ny < 0) continue;
            if(vis[ny][nx]) continue;
            vis[ny][nx] = true;
            v[ny][nx] = v[y][x] + 1;
            q.push({ny, nx});
        }
    }
}

int main() {
    int tc;

    cin >> tc;

    while(tc--) {
        int curx, cury;
        cin >> l;
        cin >> curx >> cury;
        cin >> movex >> movey;

        BFS(curx, cury);
        cout << v[movey][movex] << "\n";

        fill(v.begin(), v.end(), vector<int>(v[0].size(), 0));
        fill(vis.begin(), vis.end(), vector<bool>(vis[0].size(), 0));
    }
}