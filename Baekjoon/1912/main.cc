#include<bits/stdc++.h>

using namespace std;

int n;
const int INF = -987654321;

vector<int> vec;
int dp[1000001];

int solve(int n) {
    int ret;
    ret = dp[0] = vec[0];

    for(int i = 1; i < n; i++){
        dp[i] = max(dp[i - 1] + vec[i], vec[i]);
        ret = max(ret, dp[i]);
    }
    return ret;
}

int topDown(int cur) {
    int &ret = dp[cur];
    if(cur == 0) return 0;
    if(ret != 0) return ret;

    ret = max(vec[cur], vec[cur] + solve(cur - 1));
}

int main() {
    memset(dp, 0, sizeof(dp));

    cin >> n;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        vec.push_back(a);
    }

    cout << solve(n);
}