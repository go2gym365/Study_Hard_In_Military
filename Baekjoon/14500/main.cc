#include<bits/stdc++.h>

using namespace std;

int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

vector<vector<int>> vec(501, vector<int>(501, 0));
vector<vector<bool>> vis(501, vector<bool>(501, false));

int DFS(int yy, int xx, int cnt) {
    if(cnt == 4) {
        return vec[yy][xx];
    }

    int sum = 0;

    for(int i = 0; i < 4; i++) {
        int x = 
    }
}

int fxxkshape(int yy, int xx) {

}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> vec[i][j];
        }
    }

    int res = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            vis[i][j] = true;
            res = max(res, DFS(i, j, 1));
            res = max(res, fxxkshape(i, j));
            vis[i][j] = false;
        }
    }
}