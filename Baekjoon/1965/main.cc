#include<bits/stdc++.h>
//LIS Algorithm
using namespace std;

int dp[1001];
vector<int> vec;

int n;
int ans = 0;

int solve(int cur) {
    int &ret = dp[cur];
    if(cur == n) return 0;
    if(ret != 0) return ret;

    ret = 1;

    for(int i = 0; i  <n ; i++) {
        solved(i)
    }
}

int main() {
    memset(dp, 0, sizeof(dp));

    cin >> n;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;

        vec.push_back(a);
    }

    solve(0);

    for(int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans;
}