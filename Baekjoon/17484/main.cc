#include <bits/stdc++.h>

using namespace std;

int n, m;

int space[10][10];
int dp[10][10][4];


//0:왼 1:dir 2:오
int solve(int y, int x, int prev) {
    if(y == n) return 0;
    int &ret = dp[y][x][prev];
    
    if(ret != -1) return ret;
    
    ret = 0x3f3f3f3f;
    
    if(x-1 >= 0 && prev != 0) {
        ret = min(ret, solve(y+1, x-1, 0) + space[y][x]);
    }
    
    if(x+1 < m && prev != 2) {
        ret = min(ret, solve(y+1, x+1, 2) + space[y][x]);
    }
    
    if(prev != 1) {
        ret = min(ret, solve(y+1, x, 1)+space[y][x]);
    }
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> space[i][j];
        }
    }
    
    int ans = 0x3f3f3f3f;
    
    for(int i = 0; i < m; i++) {
        ans = min(ans, solve(0, i, 3));
    }
    
    cout << ans;
}
