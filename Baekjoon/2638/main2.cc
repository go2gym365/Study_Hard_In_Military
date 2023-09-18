#include <bits/stdc++.h>

using namespace std;

int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

vector<vector<int>> cheese(101, vector<int>(101, 0));
vector<vector<bool>> vis(101, vector<bool>(101, false));
bool meltCnt[101][101];
bool isAir[101][101];

void isInsideAir() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    vis[0][0] = true;
    isAir[0][0] true;

    while(!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;

        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if(cheese[ny][nx] == 1) continue;
            if(isAir[])
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(meltCnt, false, sizeof(meltCnt));
    
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> cheese[i][j];
        }
    }

    while(true) {
        isInsideAir();
    }
}