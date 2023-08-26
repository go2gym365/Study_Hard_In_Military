#include<bits/stdc++.h>

using namespace std;

int n, m;
int answer = -9572691;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

vector<vector<int>> vec(51, vector<int> (51, 0));
vector<vector<bool>> vis(51, vector<bool> (51, false));
vector<pair<int, int>> virus;

queue<pair<int, int>> q;

void resetVis() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            vis[i][j] = false;
        }
    }
}

int BFS() {
    int days = 0;

    while (1) {
        queue<pair<int, int>> future;

        while (!q.empty()) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (vec[ny][nx] == 1 && vec[ny][nx] == 2) continue;
                if (vis[ny][nx]) continue;

                vis[ny][nx] = true;
                future.push({ny, nx});
            }
        }
        if (future.empty()) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (vec[i][j] == 0 && !vis[i][j])
                        return -1;
                }
            }
            return days;
        }
        q = future;
        days++;
    }
    return 7;
}

void combination(int cnt, int idx) {
    if(cnt == m) {
        int res = BFS();
        answer = max(answer, res);
        resetVis();
        return;
    }

    for(int i = idx + 1; i < virus.size(); i++) {
        q.push({virus[idx].first, virus[idx].second});
        vis[virus[idx].first][virus[idx].second] = true;
        combination(cnt + 1, i);
    }

    return;
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> vec[i][j];

            if(vec[i][j] == 2) {
                virus.push_back({i, j});
            }
        }
    }

    combination(0, 0);

    cout << answer;
}