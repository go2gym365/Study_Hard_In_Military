#include<bits/stdc++.h>

using namespace std;

int n;

int dp[501][501];

vector<vector<int>> vec;

int solve(int floor, int idx) {
    if(floor == n) return 0;
    int &ret = dp[floor][idx];
    if(ret != -1) return ret;

    ret = 0;

    for(int i = idx; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ret = max(ret, solve(floor + 1, j) + vec[floor][idx]);
            ret = max(ret, solve(floor + 1, j - 1) + vec[floor][idx]);
        }
    }
    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int a;
            cin >> a;
            vec[i].push_back(a);
        }
    }

    cout << solve(0, 0);
}