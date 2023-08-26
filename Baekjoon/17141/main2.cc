#include<bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
int n, m;
int spaceCount = 0;
int ans = INF;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool pick[10];
vector<vector<int>> vec(51, vector<int> (51, 0));
vector<vector<bool>> vis(51, vector<bool> (51, false));
vector<pair<int, int>> virus;
vector<pair<int, int>> pickVirus;

bool check() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(vec[i][j] == 1) continue;
            if(!vis[i][j]) return false;
        }
    }
    return true;
}

void BFS() {
    queue<pair<int, int>> q;

    for(int i = 0; i < pickVirus.size(); i++) {
        q.push({pickVirus[i].first, pickVirus[i].second});
        vis[pickVirus[i].first][pickVirus[i].second] = true;
    }
    int cnt = 0;

    while(!q.empty()) {
        for(int i = 0; i < q.size(); i++) {
            int x = q.front().second;
            int y = q.front().first;
            q.pop();

            for(int j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];

                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if(vec[ny][nx] == 1 || vis[ny][nx]) continue;

                vis[ny][nx] == true;
                q.push({ny, nx});
            }
        }
        if(q.size() != 0) cnt++;
    }
    if(check()) {
        ans = min(ans, cnt);
    }
}

void visReset() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            vis[i][j] = false;
        }
    }
}

void combination(int idx, int cnt) {
    if(cnt == m) {
        visReset();
        BFS();
        return;
    }

    for(int i = idx; i < virus.size(); i++) {
        if(pick[i]) continue;
        pick[i] = true;
        pickVirus.push_back(virus[i]);
        combination(i + 1, cnt + 1);
        pickVirus.pop_back();
        pick[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> vec[i][j];
            if(vec[i][j] == 2) virus.push_back({i, j});
        }
    }

    combination(0, 0);

    if(ans == INF) cout << -1;
    else cout << ans;
}