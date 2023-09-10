#include<bits/stdc++.h>

using namespace std;

vector<string> vec(1001, "");
bool vis[1001][1001];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int n, m;
int sttofi = 0;
int fitoho = 0;
int fx = 0;
int fy = 0;

int startToFish(int yy, int xx) {
    queue<pair<int, int>> q;
    int count = 0;
    //물고기 찾았는지a
    bool find = false;
    q.push({yy, xx});
    vis[yy][xx] = true;

    while(true) {
        //이동했는지?
        bool move = false;
        while(!q.empty()) {
            int x = q.front().second;
            int y = q.front().first;
            q.pop();

            if(vec[y][x] == 'F') {
                find = true;
                fx = x;
                fy = y;
                break;
            }

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if(vis[ny][nx]) continue;
                if(vec[ny][nx] == 'D') continue;
                move = true;
                q.push({ny, nx});
                vis[ny][nx] = true;
            }
        }
        if(find && !move) return count;
        else if(!find && !move) return -1;
        count++;
    }    
    return count;
}

int fishToHome(int yy, int xx) {
    queue<pair<int, int>> q;
    int count = 0;
    //물고기 찾았는지
    bool home = false;
    q.push({yy, xx});
    vis[yy][xx] = true;

    while(true) {
        //이동했는지?
        bool move = false;
        while(!q.empty()) {
            int x = q.front().second;
            int y = q.front().first;
            q.pop();

            if(vec[y][x] == 'H') {
                home = true;
                break;
            }

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if(vis[ny][nx]) continue;
                if(vec[ny][nx] == 'D') continue;
                move = true;
                q.push({ny, nx});
                vis[ny][nx] = true;
            }
        }
        if(home && !move) return count;
        else if(!home && !move) return -1;
        count++;
    }    
    return count;
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    for(int i = 0; i < n; i++) {
        bool move = false;
        for(int j = 0; j < m; j++) {
            if(vec[i][j] = 'S') {
                move = true;
                sttofi =  startToFish(i, j);
                if(sttofi == -1) {
                    cout << -1;
                    return 0;
                }
            }
            if(move) break;
        }
        if(move) break;
    }

    memset(vis, false, sizeof(vis));

    fitoho = fishToHome(fy, fx);
    if(fitoho == -1) {
        cout << -1;
        return 0;
    }

    cout << sttofi + fitoho;
}