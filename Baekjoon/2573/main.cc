#include<bits/stdc++.h>
 using namespace std;

int n, m;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

vector<vector<int>> glacier(301, vector<int> (301, 0));
vector<vector<int>> water(301, vector<int> (301, 0));
vector<vector<bool>> vis(301, vector<bool> (301, false));

void BFS(int yy, int xx) {
    queue<pair<int, int>> q;

    q.push({yy, xx});

    while(!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;

        q.pop();

        vis[y][x] = true;

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(glacier[ny][nx] == 0) {
                water[y][x]++;
                continue;
            }
            if(vis[ny][nx]) continue;
            vis[ny][nx] = true;
            q.push({ny, nx});
        }
    }
}

void melting() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(vis[i][j]) vis[i][j] = false;
            glacier[i][j] -= water[i][j];
            if(glacier[i][j] < 0) glacier[i][j] = 0;
            water[i][j] = 0;
        }
    }
}

 int main() {
    ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
    int ans = 0;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> glacier[i][j];
        }
    }
    
     
    bool check = false;

    while(1) {
        //cnt > BFS를 몇번 돌았는지 체크 || 1이상이면 돌긴 했음 / 0이면 한번도 안돌았으니까 while문 탈출
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(vis[i][j]) continue;
                if(glacier[i][j] == 0) continue;
                cnt++;
                BFS(i, j);
            }
        }
        if(cnt >= 2) {
            check = true;
            break;
        }
        else if(cnt == 0) {
            break;
        }
        melting();
        ans++;
    }

    if(check) cout << ans;
    else cout << 0;
 }