#include<bits/stdc++.h>

using namespace std;

int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

char input[1001][1001];
bool vis[1001][1001];

queue<pair<int, int>> fire;
queue<pair<int, int>> jihun;

queue<pair<int, int>> tempFire;
queue<pair<int, int>> tempJihun;

int BFS() {
    int escapeTime = 0;
    
    while(1) {
        bool jihunMoveCheck = false;

        while(!fire.empty()) {
            int fy = fire.front().first;
            int fx = fire.front().second;
            fire.pop();

            for(int i = 0; i < 4; i++) {
                int fnx = fx + dx[i];
                int fny = fy + dy[i];

                if(fnx < 0 || fnx >= m || fny < 0 || fny >= n) continue;
                if(vis[fny][fnx]) continue;
                if(input[fny][fnx] == '#') continue;

                vis[fny][fnx] = true;

                tempFire.push({fny, fnx});
            }
        }

        while(!jihun.empty()) {
            int jy = jihun.front().first;
            int jx = jihun.front().second;
            jihun.pop();
             for(int i = 0; i < 4; i++) {
                int jnx = jx + dx[i];
                int jny = jy + dy[i];

                if(jnx == m || jnx == -1 || jny == n || jny == -1) {
                    return escapeTime + 1;
                }
                if(vis[jny][jnx]) continue;
                if(input[jny][jnx] == '#') continue;
                if(input[jny][jnx] == 'F') continue;
                
                vis[jny][jnx] = true;

                tempJihun.push({jny, jnx});
                jihunMoveCheck = true;
            }
        }
        if(jihunMoveCheck) {
            fire = tempFire;
            jihun = tempJihun;
            escapeTime++;
        }
        else {
            return -1;
        }

    }

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> input[i][j];

            if(input[i][j] == '#') {
                vis[i][j] = true;
            }
            else if(input[i][j] == 'J') {
                jihun.push({i, j});
                vis[i][j] = true;
            }
            else if(input[i][j] == 'F') {
                fire.push({i, j});
                vis[i][j] = true;
            }
        }
    }

    int res = BFS();

    if(res == -1) {
        cout << "IMPOSSIBLE";
    }
    else {
        cout << res;
    }
}