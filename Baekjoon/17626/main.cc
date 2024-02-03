#include<bits/stdc++.h>

using namespace std;

int n;
int dp[50001];

int ans = 0x3f3f3f3f;

int solve(int sum, int cnt) {
    if(sum == n) {
        ans = min(ans, cnt);
        return 0;
    }
    else if(sum > n) return 0x3f3f3f3f;
    
    int &ret = dp[sum];
    if(ret != -1) return ret;
    ret = 0x3f3f3f3f;
    
    for(int i = 1; i*i <= n; i++) {
        ret = min(ret, solve(sum + i*i, cnt+1) + 1);
        ret = min(ret, solve(sum, cnt));
    }
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    memset(dp, -1, sizeof(dp));
    cin >> n;
    
    cout << solve(0, 0) << endl;
    
}