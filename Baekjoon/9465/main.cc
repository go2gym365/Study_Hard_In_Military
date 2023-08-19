#include <bits/stdc++.h>

using namespace std;

int t, n;

vector<vector<int>> vec(2, vector<int>(100001, 0));
int dp[3][100001];

int solve(int prevSelect, int idx) {
    if(idx == n) return 0;
    int &ret = dp[prevSelect][idx];
    if (ret != -1)
        return ret;

    ret = 0;
    
    if (prevSelect == 0) {
        ret = max(ret, solve(1, idx + 1) + vec[0][idx]);
        ret = max(ret, solve(2, idx + 1) + vec[1][idx]);
    }
    else if(prevSelect == 1) {
        ret = max(ret, solve(2, idx + 1) + vec[1][idx]);
        ret = max(ret, solve(0, idx + 1));
    }
    else if(prevSelect == 2) {
        ret = max(ret, solve(1, idx + 1) + vec[0][idx]);
        ret = max(ret, solve(0, idx + 1));
    }
    

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> t;

    while (t--) {
        memset(dp, -1, sizeof(dp));
        cin >> n;

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cin >> vec[i][j];
            }
        }

        cout << solve(0, 0) << "\n";
    }
}