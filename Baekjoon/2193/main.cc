#include<bits/stdc++.h>

using namespace std;

long long dp[91];

long long solve(int n) {
    if(n == 1 or n == 2) return 1;
    long long &ret = dp[n];

    if(ret != 0) return ret;

    return ret = solve(n-1) + solve(n - 2);
}

int main() {
    int n;
    cin >> n;

    cout << solve(n);
}