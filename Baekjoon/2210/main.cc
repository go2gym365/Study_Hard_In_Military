#include<bits/stdc++.h>

using namespace std;

char graph[5][5];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

unordered_set<string>s;

void solve(int yy, int xx, int cnt, string str) {
    if(cnt == 6) {
        s.insert(str);
        return;
    }
    
    for(int i = 0; i < 4; i++) {
        int ny = yy + dy[i];
        int nx = xx + dx[i];
        
        if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
        
        solve(ny, nx, cnt+1, str+graph[ny][nx]);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> graph[i][j];
        }
    }
    
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            solve(i, j, 0, ""+graph[i][j]);
        }
    }
    
    cout << s.size();
}