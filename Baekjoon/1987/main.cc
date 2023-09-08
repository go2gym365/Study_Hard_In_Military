#include<bits/stdc++.h>

using namespace std;

int n, r;
int ans = 0;

vector<string> vec;
map<char, bool> m;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int solve(int x, int y) {
    int ret = 1;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 0 || nx >= r || ny < 0 || ny >= n) continue;
        if(m[vec[ny][nx]]) continue;
        m[vec[ny][nx]] = true;
        ret = max(ret, solve(nx, ny) + 1);
        m[vec[ny][nx]] = false;
    }

    return ret;
}

int main() {
    cin >> n >> r;

    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        vec.push_back(str);
    }

    m[vec[0][0]] = true;
    
    cout << solve(0, 0);
}