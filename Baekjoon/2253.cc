#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
const int INF = 0x3f3f3f3f;

int dp[10001][501];
bool che[10001];

int solve(int idx, int prev) {
    if (idx == n) return 0;
    if (idx > n || che[n]) return INF;
    int &ret = dp[idx][prev];
    if (ret != -1) return ret;

    ret = INF;

    if (!che[idx + prev]) {
        ret = min(ret, solve(idx + prev, prev) + 1);
    }
    if (!che[idx + prev - 1] && prev - 1 >= 0) {
        ret = min(ret, solve(idx + prev - 1, prev - 1) + 1);
    }
    if (!che[idx + prev + 1]) {
        ret = min(ret, solve(idx + prev + 1, prev + 1) + 1);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(dp, -1, sizeof(dp));

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        che[a] = true;
    }

    int ans = solve(1, 0);

    if (ans == INF)
        cout << -1;
    else
        cout << ans;

    return 0;
}
