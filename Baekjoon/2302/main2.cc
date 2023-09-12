#include<bits/stdc++.h>

using namespace std;

int n, m;

int dp[41];
bool vip[41];

int solve(int idx) {
    if(idx == n + 1) return 1;
    if(idx > n + 1) return 0;
    int &ret = dp[idx];
    if(ret != -1) return ret;
    if(vip[idx]) return solve(idx + 1);
    ret = 0;

    //자기 자리에 앉는 경우
    ret += solve(idx + 1);
    //자리를 바꿔앉는 경우
    if(!vip[idx + 1]) {
        ret += solve(idx + 2);
    }

    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    memset(vip, false, sizeof(vip));

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a;
        cin >> a;
        vip[a] = true;
    }

    cout << solve(1);
}