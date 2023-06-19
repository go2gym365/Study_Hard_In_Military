#include <bits/stdc++.h>

using namespace std;
int dp[15];
int N;

int solve(int cur) {
    if(cur == 0) return 1;
    if(cur < 0) return 0;
    int &ret = dp[cur];
    if(ret != -1) return ret;
    ret = 0;
    ret += solve(cur - 1);
    ret += solve(cur - 2);
    ret += solve(cur - 3);
    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T--) {
        cin >> N;
        cout << solve(N) << '\n';
    }
}