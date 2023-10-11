#include <bits/stdc++.h>

using namespace std;

int n;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

vector<vector<int>> input(101, vector<int>(101, 0));
vector<vector<bool>> vis(101, vector<bool>(101, false));

void classificationLand(int yy, int xx, int num) {
    queue<pair<int, int>> q;

    q.push({yy, xx});
    input[yy][xx] = num;

    while (!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (input[ny][nx] != -1) continue;

            input[ny][nx] = num;
            q.push({ny, nx});
        }
    }
}

int bfs(int num) {
    queue<pair<int, int>> q;
    int dis = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (input[i][j] == num) {
                q.push({i, j});
                vis[i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        int cur = q.size();
        for (int i = 0; i < cur; i++) {
            int x = q.front().second;
            int y = q.front().first;

            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (input[ny][nx] == num) continue;
                if (vis[ny][nx]) continue;

                vis[ny][nx] = true;
                if (input[ny][nx] != 0 && input[ny][nx] != num) {
                    return dis;
                }
                q.push({ny, nx});
            }
        }
        dis++;
    }

    return dis;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> input[i][j];
            if (input[i][j] == 1) {
                input[i][j] = -1;
            }
        }
    }

    int num = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (input[i][j] == -1) {
                classificationLand(i, j, num);
                num++;
            }
        }
    }

    int answer = 0x3f3f3f3f;

    for (int i = 1; i < num; i++) {
        answer = min(answer, bfs(i));
        vis.assign(101, vector<bool> (101, false));
    }

    cout << answer;
}