#include<bits/stdc++.h>

using namespace std;

int n, r;
int ans = 0;

vector<string> vec;
bool vis[26];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int solve(int x, int y) {
    int ret = 1;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 0 || nx >= r || ny < 0 || ny >= n) continue;
        if(vis[vec[ny][nx] - 'A']) continue;
        vis[vec[ny][nx] - 'A'] = true;
        ret = max(ret, solve(nx, ny) + 1);
        vis[vec[ny][nx] - 'A'] = false;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> r;

    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        vec.push_back(str);
    }

    vis[vec[0][0] - 'A'] = true;
    
    cout << solve(0, 0);
}