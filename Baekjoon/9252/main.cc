#include<bits/stdc++.h>

using namespace std;

string str1, str2;
int dp[1001][1001];
int trace[1001];
int lengthOfLCS = 0;

int solve(int s1, int s2, int length) {
    if(s1 == str1.size() || s2 == str2.size()) return 0;
    int &ret = dp[s1][s2];
    if(ret != 0) return ret;

    ret = 1;

    ret = max(ret, solve(s1 + 1, s2, length));
    ret = max(ret, solve(s1, s2 + 1, length));

    if(str1[s1] == str2[s2]) {
        trace[s1] = max(length, lengthOfLCS);
        ret = max(ret, solve(s1 + 1, s2 + 1, length + 1) + 1);
    }

    lengthOfLCS = max(lengthOfLCS, ret);
    return ret;
}

void print(int s1, int s2) {
    for(int i = str1.size() - 1; i >= 0; i--) {
        if(trace[i] == lengthOfLCS) {
            cout << str1[i];
            lengthOfLCS--;
        }
    }
}

int main() {
    memset(dp, 0, sizeof(dp));
    cin >> str1 >> str2;

    cout << solve(0, 0, 1) << "\n";
    cout << lengthOfLCS;
    for(int i = 0; i < str1.size(); i++) {
        cout << trace[i] << " ";
    }
    print(str1.size(), str2.size());
}