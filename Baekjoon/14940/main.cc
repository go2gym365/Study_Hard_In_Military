#include<bits/stdc++/.h>

using namespace std;

vector<vector<int>> v(1001, vector<int>(1001, 0));
vector<vector<int>> vis(1001, vector<int>(1001, -1));

int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void BFS(int yy, int xx) {
    queue<pair<int, int>> q;
    q.push({yy, xx});

    vis[yy][xx] = 0;

    if(!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;
        
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(v[ny][nx] = 0) continue;
        }
    }
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin > v[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v[i][j] == 2) 
                BFS(i, j);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}