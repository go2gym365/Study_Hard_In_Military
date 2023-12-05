#include <bits/stdc++.h>

using namespace std;

int n, k;

int dp[1001][1001][2];
int vis[1001];

int solve(int idx, int cnt, int type) {
    if(cnt == k) return 1;
    if(idx == n-1 && cnt == k-1) {
        if(type == 0) return 1;
        else return 0;
    }
    if(idx >= n || cnt > k) return 0;
    
    int &ret = dp[idx][cnt][type];
    if(ret != -1) return ret;
    
    ret = 0;
    
    ret += solve(idx+1, cnt, type);
    ret += solve(idx+2, cnt+1, type);
    
    return ret %= 1000000003;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> n >> k;
    
    cout << (solve(1, 0, 0) + solve(2, 1, 1)) % 1000000003;
}
