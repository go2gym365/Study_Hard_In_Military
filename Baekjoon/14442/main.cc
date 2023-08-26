#include<bits/stdc++.h>

using namespace std;

int n, m, k;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

vector<string> vec(1001, "");
int vis[1001][1001][11];

int BFS() {
    queue<pair<pair<int, int>, int>> q;

    vis[0][0][0] = 1;

    q.push({{0, 0}, 0});

    while(!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int cnt = q.front().second;

        q.pop();

        if(y == n - 1 && x == m - 1) {
            return vis[y][x][cnt];
        }

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;

            if(vec[ny][nx] == '1' && cnt < k) {
                vis[ny][nx][cnt + 1] = vis[y][x][cnt] + 1;
                q.push({{ny, nx}, cnt + 1});
            }

            if(vec[ny][nx] == '0' && vis[ny][nx][cnt] == 0) {
                vis[ny][nx][cnt] = vis[y][x][cnt] + 1;
                q.push({{ny, nx}, cnt});
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;

    for(int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    cout << BFS();
}