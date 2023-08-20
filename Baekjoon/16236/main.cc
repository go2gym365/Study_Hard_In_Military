#include<bits/stdc++.h>

using namespace std;

int n;
int sharkSize = 2;
int feedcnt = 0;
bool huntCheck = false;
bool eat = false;
int ans = 0;

int sharkX;
int sharkY;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

vector<vector<int>> vec(21, vector<int>(21, 0));
vector<vector<bool>> vis(21, vector<bool>(21, false));

void BFS(int yy, int xx) {
    queue<pair<pair<int, int>, int>> q;
    int time = 0;
    q.push({{yy, xx}, 0});

    while(!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int cnt = q.front().second;

        vis[y][x] == true;

        if(vec[y][x] > 0 && vec[y][x] < sharkSize && time == cnt) {
            if((sharkY > y) || (sharkY == y && sharkX > x)) {
                sharkX = x;
                sharkY = y;
                continue;
            }
        }
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(vis[ny][nx]) continue;
            if(vec[ny][nx] <= sharkSize) {
                if(vec[ny][nx] > 0 && vec[ny][nx] < sharkSize && !eat) {
                    eat = true;
                    sharkX = nx;
                    sharkY = ny;
                    time = cnt + 1;
                    ans += time;
                }
                else {
                    q.push({{ny, nx}, cnt + 1});
                    vis[ny][nx] = true;
                }
            }
        }
    }
}

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> vec[i][j];
            if(vec[i][j] == 9) {
                sharkX = j;
                sharkY = i;
                vec[i][j] = 0;
            }
        }
    }

    while(!huntCheck) {
        fill(vis.begin(), vis.end(), vector<bool> (21, false));
        BFS(sharkY, sharkX);
        if(eat) {
            eat = false;
            feedcnt++;
            vec[sharkY][sharkX] = 0;
            if(feedcnt == sharkSize) {
                sharkSize++;
                feedcnt = 0;
            }
        }
        else {
            huntCheck = true;
        }
    }

    cout << ans;
}