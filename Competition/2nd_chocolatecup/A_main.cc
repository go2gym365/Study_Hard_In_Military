#include<bits/stdc++.h>

using namespace std;

vector<string> v;
vector<vector<bool>> vis(3, vector<bool>(3, false));

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int BFS(int yy, int xx) {
    int cnt = 0;

    queue<pair<int, int>> q;
    q.push({yy, xx});

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        cnt++;
        q.pop();
        vis[y][x] = true;
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx > 3 || nx < 0 || ny > 3 || ny < 0) continue;
            if(v[ny][nx] == '-' || v[ny][nx] == 'X') continue;
            if(vis[ny][nx]) continue;

            q.push({ny, nx});
        }
    }

    return cnt;
}

int main() {
    int t;
    
    cin >> t;

    while(t--) {
        vector<int> ex;
        vector<int> Count;
        int n, m;
        bool check = true;

        for(int i = 0; i < 3; i++) {
            string str;
            cin >> str;
            v.push_back(str);
        }

        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> m;
            ex.push_back(m);
        }
        int cnt = 0;

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(v[i][j] == 'O') {
                    cnt = BFS(i, j);
                    Count.push_back(cnt);
                }
            }
        }
        sort(Count.begin(), Count.end());
        
        for(int i = 0; i < 3; i++) {
            if(Count[i] != ex[i]) check = false;
        }

        if(check) cout << 1;
        else cout << 0;
    }
}