#include<bits/stdc++.h>

using namespace std;

vector<vector<char>>v(601, vector<char>(601, 0));
vector<vector<bool>>vis(601, vector<bool>(601, false));

int n, m;
int cnt = 0;
bool check = false;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void BFS(int yy, int xx) {
    queue<pair<int, int>> q;
    q.push({yy, xx});

    while(!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        
        if(v[y][x] == 'P') cnt++;

        

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(vis[ny][nx]) continue;
            if(v[ny][nx] == 'X') continue;

            vis[ny][nx] = true;
            q.push({ny, nx});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v[i][j] == 'I') {
                vis[i][j] = true;
                BFS(i, j);
                
                break;                
            } 
        }
    }

    if(cnt > 0) cout << cnt;
    else cout << "TT";
}