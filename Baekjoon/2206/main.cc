#include<bits/stdc++.h>

using namespace std;

int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

vector<string> vec(1001, "");
int vis[1001][1001][2];

int BFS(int yy, int xx) {
    queue<pair<pair<int, int>, int>> q;

    vis[yy][xx][1] = 1;

    q.push({{yy, xx}, 1});

    while(!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int crush = q.front().second;

        if(y == n - 1 && x == m - 1) {
            return vis[y][x][crush];
        }

        q.pop();

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(vec[ny][nx] == 1 && crush) {
                vis[ny][nx][0] = vis[y][x][crush] + 1;
                q.push({{ny, nx}, 0});
            }
            if(vec[ny][nx] == 0 && vis[ny][nx][crush] == 0) {
                vis[ny][nx][crush] = vis[y][x][crush] + 1;
                q.push({{ny, nx}, crush});
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    cout << BFS(0, 0);
}