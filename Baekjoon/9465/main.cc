#include <bits/stdc++.h>

using namespace std;

int t, n;

vector<vector<int>> vec(2, vector<int>(100001, 0));
int dp[2][100001];

int solve(int y, int x) {
    if (x == n)
        return 0;
    int &ret = dp[y][x];
    if (ret != -1)
        return ret;

    ret = 0;
    
    if (y == 0) {
        ret += max(ret, solve(y + 1, x + 1) + vec[y][x]);
        ret += max(ret, solve(y + 1, x + 1) + vec[y][x]);
        ret += max(ret, solve(y + 1, x + 1) + vec[y][x]);
    }
}

int main() {
    memset(dp, -1, sizeof(dp));

    cin >> t;

    while (t--) {

        cin >> n;

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cin >> vec[i][j];
            }
        }

        solve(0, 0);
    }
}