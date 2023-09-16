#include<bits/stdc++.h>

using namespace std;

int dp[1001][1001];
string str1, str2;

int solve(int s1Idx, int s2Idx) {
    // 기저조건(각 문자열 끝까지 돌면 리턴)
    if(s1Idx == str1.length() || s2Idx == str2.length()) return 0;
    int &ret = dp[s1Idx][s2Idx];

    if(ret != -1) return ret;

    // str1 끝까지 안갔으면 그다음 인덱스의 문자 확인
    if(s1Idx < str1.length()) {
        ret = max(ret, solve(s1Idx + 1, s2Idx));
    }

    // str2 끝까지 안갔으면 그다음 인덱스의 문자 확인
    if(s2Idx < str2.length()) {
        ret = max(ret, solve(s1Idx, s2Idx + 1));
    }

    // 만약 각 인덱스의 문자와 같으면 +1
    if(str1[s1Idx] == str2[s2Idx]) {
        ret = max(ret, solve(s1Idx + 1, s2Idx + 1) + 1);
    }

    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> str1 >> str2;

    cout << solve(0, 0);
}