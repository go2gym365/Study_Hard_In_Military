#include<bits/stdc++.h>

using namespace std;

vector<string> vec(26, "");
vector<vector<bool>> vis(26, vector<bool>(26, false));
vector<int> ans;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int n;

void BFS(int yy, int xx) {
    int cnt = 0;
    queue<pair<int, int>> q;
    q.push({yy, xx});
    vis[yy][xx] = true;
    
    while(!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;
        cnt++;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= n || nx < 0 || ny >= n || ny < 0) continue;
            if(vec[ny][nx] == '0') continue;
            if(vis[ny][nx] == true) continue;
            vis[ny][nx] = true;
            q.push({ny, nx});            
        }
    }
    ans.push_back(cnt);
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(vec[i][j] == '1' && !vis[i][j]) {
                BFS(i, j);
            }
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }
}