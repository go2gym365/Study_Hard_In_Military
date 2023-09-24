#include<bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> input;
int dp[501][501];

int solve(int prevSelect, int idx) {
    if(idx == n) return 0;
    int &ret = dp[prevSelect][idx];
    if(ret != -1) return ret;

    ret = 0;

    for(int i = idx; i < n; i++) {
        if(prevSelect < input[i].second) {
            ret = max(ret, solve(input[i].second, i + 1) + 1);
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> n;

    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        input.push_back({a, b});
    }

    sort(input.begin(), input.end());

    cout << n - solve(0, 0);
}