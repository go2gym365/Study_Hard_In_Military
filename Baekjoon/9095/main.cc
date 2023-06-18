#include<bits/stdc++.h>

using namespace std;

const int INF = 987654321;

vector<int> dp(20, -1);

int main() {
    int T;
    cin >> T;
    dp[1] = 1; dp[2] = 2; dp[3] = 4;
    for(int i = 4; i < 11; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    for(int i = 0; i < T; i++) {
        int n;
        cin >> n;

        cout << dp[n] << "\n";
    }
}