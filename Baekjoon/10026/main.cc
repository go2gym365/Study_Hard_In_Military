#include<bits/stdc++.h>

using namespace std;

int n;

vector<string> vec(101, "");
vector<vector<bool>> vis(101, vector<bool>(101, 0));

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void BFS_RG(int yy, int xx) {
    queue<pair<int, int>> q;
    q.push({yy, xx});
    vis[yy][xx] = true;

    while(q.empty()) {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(vis[ny][nx]) continue;
            if(vec[ny][nx] == 'B') continue;

            q.push({ny, nx});
        }
    }
}

void BFS_RGB(int yy, int xx) {
    queue<pair<int, int>> q;
    q.push({yy, xx});
    vis[yy][xx] = true;

    while(q.empty()) {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(vis[ny][nx]) continue;
            if(vec[ny][nx] == 'B') continue;

            q.push({ny, nx});
        }
    }
}

int main() {
    cin >> n;
    int cntRG = 0;
    int cntRGB = 0;

    for(int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!vis[i][j] && vec[i][j] == 'R' || vec[i][j] == 'G') {
                BFS_RG(i, j);
                cntRG++;
            }
        }
    }
    cout << cntRG << " ";
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!vis[i][j] && vec[i][j] == 'R' || vec[i][j] == 'G') {
                BFS_RGB(i, j);
            }
        }
    }
}