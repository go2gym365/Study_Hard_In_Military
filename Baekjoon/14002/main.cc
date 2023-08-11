#include<bits/stdc++.h>

using namespace std;

int n;

vector<int> vec;

int dp[1001][1001];
int trace[1001];

int solve(int prev, int idx) {
    if(idx == n) return 0;
    int &ret = dp[prev][idx];
    if(ret != -1) return ret;

    ret = 0;

    for(int i = idx; i < n; i++) {
        if(prev < vec[i]) {
            trace[idx] = prev;
            ret = max(ret, solve(vec[i], idx + 1) + 1);
        }
    }
    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    memset(trace, -1, sizeof(trace));

    cin >> n;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;

        vec.push_back(a);
    }

    int ans = solve(0, 0);
    cout << ans << "\n";

    for(int i = 0; i < 15; i++) {
        cout << trace[i] << " ";
    }
}