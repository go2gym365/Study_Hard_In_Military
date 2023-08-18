#include<bits/stdc++.h>

using namespace std;

int n;

vector<int> vec;

int dp[201];

int solve(int now) {
    if(now == n) return 0;
    int &ret = dp[now];
    if(ret != -1) return ret;
    ret = 1;

    for(int i = now + 1; i < n; i++) {
        if(vec[now] < vec[i]) {
            ret = max(ret, solve(i) + 1);
        }
    }
    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));

    cin >> n;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;

        vec.push_back(a);
    }

    for(int i = 0; i < n; i++) {
        solve(i);
    }

    cout << dp[n - 1];
}