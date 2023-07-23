#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> vec(5, vector<int>(5, 0));
vector<vector<bool>> vis(5, vector<bool>(5, false));

int n, m;
int ans = -987654321;

int downRight(int y, int x) {
    return vec[y][x] + vec[y + 1][x] + vec[y + 1][x + 1];
}

void DFS(int y, int x, int sum) {
    if(x == m) {
        x == 0;
        y++;
    }
    if(y == n) {
        ans = max(ans, sum);
        return;
    }

    if(!vis[y][x]) {
        if(x + 1 < m && y + 1 < n && !vis[y + 1][x] && !vis[y + 1][x + 1]) {
            vis[y][x] = true;
            vis[y + 1][x] = true;
            vis[y + 1][x + 1] = true;
            int temp = sum + downRight(y, x);
            DFS(y, x + 1, temp);
            vis[y][x] = false;
            vis[y + 1][x] = false;
            vis[y + 1][x + 1] = false;
        }
        if(x + 1 < m && y + 1 < n && !vis[y][x + 1] && !vis[y + 1][x + 1]) {
            vis[y][x] = true;
            vis[y][x + 1] = true;
            vis[y + 1][x + 1] = true;
            int temp = sum + 
        }
    }
    DFS(y, x + 1, sum);
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> vec[i][j];
        }
    }

    DFS(0, 0, 0);

    
}