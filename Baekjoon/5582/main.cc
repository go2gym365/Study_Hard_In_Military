#include<bits/stdc++.h>

using namespace std;

int dp[4001][4001];

string str1, str2;

int solve(int s1, int s2) {
    if(s1 == str1.size() || s2 == str2.size()) return 0;
    int &ret = dp[s1][s2];
    if(ret != -1) return ret;

    ret = 0;

    if(s1 < str1.length()) {
        ret = max(ret, solve(s1 + 1, s2));
    }

    if(s2 < str2.length()) {
        ret = max(ret, solve(s1, s2 + 1));
    }

    if(str1[s1] == str2[s2]) {
        cout << s1 << " " << s2 << " " << ret << "\n";
        ret = max(ret, solve(s1 + 1, s2 + 1) + 1);
    }

    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> str1 >> str2;

    cout << solve(0, 0);
}