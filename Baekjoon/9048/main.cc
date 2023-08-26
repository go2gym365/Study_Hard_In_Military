#include<bits/stdc++.h>

using namespace std;

int t;

int main() {
    cin >> t;

    while(t--) {
        vector<int> vec;
        int dp[10001] = {};

        int n, m;
        cin >> n;

        for(int i = 0; i < n; i++) {
            int a;
            cin >> a;

            vec.push_back(a);
        }

        cin >> m;

        dp[0] = 1;

        for(int i = 0; i < n; i++) {
            for(int j = vec[i]; j <= m; j++) {
                dp[j] += dp[j-vec[i]];
            }
        }

        cout << dp[m] << "\n";
    }
}