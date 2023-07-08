#include<bits/stdc++.h>

using namespace std;

vector<string> vec(25, "");
vector<vector<bool>> vis(25, vector<bool>(25, false));
vector<int> ans;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int n;

void BFS(int yy, int xx) {
    int cnt = 0;
    queue<pair<int, int>> q;
    q.push({yy, xx});

    while(!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;
        vis[y][x] = true;
        cnt++;

        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= n || nx < 0 || ny >= n || ny < 0) continue;
            if(vec[ny][nx] == '0') continue;
            q.push({ny, nx});
        }
    }

    ans.push_back(cnt);
}

int main() {
    cin >> n;
    int count = 0;
    for(int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(vec[i][j] == '1') {
                count++;
                BFS(i, j);
            }
        }
    }

    cout << count << "\n";
    for(int i = 0; i < count; i++) {
        cout << ans[i] << "\n";
    }
}