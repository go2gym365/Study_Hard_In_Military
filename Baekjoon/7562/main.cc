#include<bits/stdc++.h>

using namespace std;

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

int l, curx, cury;
int movex, movey;

vector<vector<int>>v(301, vector<int>(301, 0));
vector<vector<bool>>vis(301, vector<bool>(301, false));

void BFS() {
    queue<pair<int, int>> q;
    q.push({cury, curx});
    if(curx)

    while(!q.empty()){
        int x = q.front().second;
        int y = q.front().first;
        vis[y][x] = true;
        q.pop();
        
        for(int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= l || nx < 0 || ny >= l || ny < 0) continue;
            if(vis[ny][nx]) continue;
        }
    }
}

int main() {
    int tc;

    cin >> tc;

    while(tc--) {
        cin >> l;
        cin >> curx >> cury;
        cin >> movex >> movey;

        BFS();

        fill(v.begin(),v.end(), vector<int>(301, 0));
    }
}