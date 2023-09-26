#include<bits/stdc++.h>

using namespace std;

string str1, str2;
int dp[1001][1001];
char trace[1001];

void solve() {
    for(int i = 1; i <= str1.length(); i++) {
        for(int j = 1; j <= str2.length(); j++) {
            if(str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else 
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << dp[str1.size()][str2.size()] << "\n";
}

void print(int s1, int s2) {
    if(dp[s1][s2] == 0) return;

    if(str1[s1 - 1] == str2[s2 - 1]) {
        print(s1 - 1, s2 - 1);
        cout << str1[s1 - 1];
    }
    else 
    dp[s1-1][s2] > dp[s1][s2-1] ? print(s1 - 1, s2) : print(s1, s2 - 1);
}

int main() {
    memset(dp, 0, sizeof(dp));
    cin >> str1 >> str2;

    solve();

    print(str1.size(), str2.size());
}