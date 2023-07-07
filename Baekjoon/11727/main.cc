#include<bits/stdc++.h>

using namespace std;

int dp[3][1001];

int n;

int solve(int type, int length) {
    int &ret = dp[type][length];
    if(ret != -1) return ret;
    if(length == n) return 1;
    ret = 0;

    ret += solve(0, length + 1);
    if(length + 2 <= n) {
        ret += solve(1, length + 2);
        ret += solve(2, length + 2);
    }

    return ret = ret % 10007; //dp배열에 나머지 연산을 한 값 자체를 저장하고 리턴
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    memset(dp, -1, sizeof(dp));

    cin >> n;

    cout << solve(0, 0);
}