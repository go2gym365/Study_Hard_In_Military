#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> v(301, vector<int>(301, 0));
vector<vector<bool>> vis(301, vector<bool>(301, false));

void DFS(int yy, int xx) {
    vis[yy][xx] = true;

    for(auto node : v) {
        
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            DFS(i, j);
        }
    }
}