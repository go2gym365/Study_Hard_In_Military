#include<bits/stdc++.h>

using namespace std;

int n;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

vector<vector<int>> input(101, vector<int> (101, 0));
vector<vector<bool>> vis(101, vector<bool> (101, false));

void bfs() {
    queue<pair<int, int>> q;

    
    while(!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;

        vis[y][x] = true;

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny =  y + dy[i];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; i++) {
            cin >> input[i][j];
        }
    }


}