#include<bits/stdc++.h>

using namespace std;

int n, k;

vector<int> vec;
int dp[10001];

int solve() {
    dp[0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = vec[i]; j <= k; j++) {
            dp[j] += dp[j - vec[i]];
        }
    }

    return dp[k];
}

int main() {
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;

        vec.push_back(a);
    }

    cout << solve();
}