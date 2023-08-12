#include <bits/stdc++.h>

using namespace std;

int n;

vector<int> vec;

int dp[1001][1001];
int trace[1001][1001];

int maxValue = 0;
int maxIdx = -1;

int solve(int prev, int idx) {
    printf("HI");
    if (idx == n)
        return 0;
    int &ret = dp[prev][idx];
    if (ret != -1)
        return ret;

    ret = 0;

    for (int i = idx; i < n; i++) {
        if (prev < vec[i]) {
            ret = max(ret, solve(vec[i], i + 1) + 1);
        }
    }
    
    if (maxValue < ret) {
        maxIdx = idx;
        maxValue = ret;
        cout << idx << " " << ret << endl;
    }
    return ret;
}

void tr(int prev, int idx) {
    if (idx >= n) return;
    cout << vec[idx] << " ";
    int current = solve(prev, idx);
    cout << current << "\n";
    for (int i=idx; i<n; i++) {
        if (prev >= vec[i]) continue;
        if (current - 1 == solve(vec[i], i+1)) tr(vec[i], i+1);
    }
}
// 6
// 50 20 10 30 20 50
int main() {
    memset(dp, -1, sizeof(dp));
    memset(trace, -1, sizeof(trace));

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        vec.push_back(a);
    }

    int ans = solve(0, 0);
    cout << ans << "\n";

    tr(0, maxIdx);

    // for(int i = 0; i < 1001; i++) {
    //     if(trace[i] == -1) continue;
    //     cout << trace[i] << " ";
    // }
}