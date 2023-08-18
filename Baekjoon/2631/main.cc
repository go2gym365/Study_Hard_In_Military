#include<bits/stdc++.h>

using namespace std;

int n;

vector<int> vec;

int dp[201];

int calcMax() {
    int ret = 0;
    for(int i= 0; i < n; i++) {
        ret = max(ret, dp[i]);
    }
    return ret;
}

int solve(int now) {
    int &ret = dp[now];
    if(ret != -1) return ret;
    ret = 1;

    for(int i = 0; i < now; i++) {
        if(vec[i] < vec[now]) {
            ret = max(ret, solve(i) + 1);
        }
    }
    return ret;
}

int solve(int now, int next)

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

    cout << n - calcMax();
}