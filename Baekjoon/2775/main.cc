#include<bits/stdc++.h>

using namespace std;

int dp[15];

int solve(int a, int b) {
    if(b == 1) return 1;
    if(a == 0) return b;
    return solve(a - 1, b) + solve(a, b - 1);
}

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int k, n;
        cin >> k >> n;

        cout << solve(k, n) << "\n";
    }
}