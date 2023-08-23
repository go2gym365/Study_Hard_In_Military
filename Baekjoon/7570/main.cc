#include<bits/stdc++.h>

using namespace std;

int n;

vector<int> vec;

int dp[1000001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int ans = -0x3f3f3f3f;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        dp[a] = dp[a - 1] + 1;
        ans = max(ans, dp[a]);
    }

    cout << n - ans;
}