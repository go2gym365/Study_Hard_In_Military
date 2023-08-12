#include<bits/stdc++.h>

using namespace std;

int n;

vector<pair<int, int>> vec;
int dp[1500001];

int solve(int cur) {
    if(cur == n) return 0;
    int &ret = dp[cur];
    if(ret != -1) return ret;

    ret = 0;

    //상담 할때
    if(cur + vec[cur].first <= n) {
        ret = max(ret, solve(cur + vec[cur].first) + vec[cur].second);
    }
    //안하고 넘어갈때
    ret = max(ret, solve(cur + 1));

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> n;

    for(int i = 0; i < n; i++) {
        int time, cost;
        cin >> time >> cost;
        vec.push_back({time, cost});
    }

    cout << solve(0);
}