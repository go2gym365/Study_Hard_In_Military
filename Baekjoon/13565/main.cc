#include<bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int M, N;
bool ans = false;
vector<vector<int>> v(1001, vector<int>(1001, 0));
vector<vector<bool>> vis(1001, vector<bool>(1001, false));

void BFS(int yy, int xx) {
    queue<pair<int, int>> q;
    q.push({yy, xx});
    vis[yy][xx] = true;

    while(!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= N || nx < 0 || ny >= M || ny < 0)
                continue;
            if(v[ny][nx] == '1' || vis[ny][nx])
                continue;
            q.push({ny, nx});
            vis[ny][nx] = true;
            if(ny == M - 1)
                ans = true;
        }
    }
    // for(int i = 0; i < M; i++) {
    //     if(v[M - 1][i])
    //         ans = true;}
    
}

int main() {
    cin >> M >> N;

     for(int i = 0; i < M; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < N; j++) {
            v[i][j] = str[j];
        }
     }

    for(int j = 0; j < N; j++) {
        if(v[0][j] == '0' && !vis[0][j]) {
            BFS(0, j);
        }
    }

    if(ans)
        cout << "YES";
    else
        cout << "NO";
}