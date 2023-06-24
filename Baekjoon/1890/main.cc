#include<bits/stdc++.h>

using namespace std;

int n;

vector<vector<int>> v(101, vector<int>(101, 0));
long long dp[101][101];

long long solve(int y, int x) {
    if(x == n - 1 && y == n - 1) return 1;
    long long &ret = dp[y][x];
    if(ret != -1) return ret;
    ret = 0;

    if(x != n - 1 && x + v[y][x]) ret += solve(y, x + v[y][x]);
    if(y != n - 1 && y + v[y][x]) ret += solve(y + v[y][x], x);

    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    cout << solve(0, 0);
}