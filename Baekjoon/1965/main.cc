#include<bits/stdc++.h>

using namespace std;

int dp[1001];
vector<int> vec;

int n;
int ans = 0;

void solve() {
    for(int i = 0; i < n; i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if(vec[i] > vec[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
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

    solve();
    for(int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans;
}