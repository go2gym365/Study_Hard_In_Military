#include<bits/stdc++.h>

using namespace std;

const int MOD = 1000000009;
int T;

int dp[100001][4];

int solve(int c, int n) {
    if(n == 0) return 1;
    int &ret = dp[n][c];
    if(ret != -1) return ret;
    ret = 0;
    if(c == 0) {
        ret += solve(1, n - 1);
        ret %= MOD;
        ret += solve(2, n - 2);
        ret %= MOD;
        ret += solve(3, n - 3);
        ret %= MOD;
    }
    if(c == 1) {
        ret += solve(2, n - 2);
        ret %= MOD;
        ret += solve(3, n - 3);
        ret %= MOD;
    }
    if(c == 2) {
        ret += solve(1, n - 1);
        ret %= MOD;
        ret += solve(3, n - 3);
        ret %= MOD;
    }
    if(c == 3) {
        ret += solve(1, n - 1);
        ret %= MOD;
        ret += solve(2, n - 2);
        ret %= MOD;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> T;
    for(int i = 0; i < T; i ++) {
        int n;
        cin >> n;
        cout << solve(0, n) << "\n";
    }
}