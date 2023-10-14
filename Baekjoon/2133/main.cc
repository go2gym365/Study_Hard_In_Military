#include<bits/stdc++.h>

using namespace std;

int n;
int dp[8][93];

int solve(int type, int idx) {
    if(idx == n) {
        if(type == 0)  return 1;
        else return 0;
    }
    
    int &ret = dp[type][idx];
    if(ret != -1) return ret;

    ret = 0;

    if(type == 0) {
        ret += solve(1 | (1 << 1) | (1 << 2), idx + 1);
        ret += solve(1, idx + 1);
        ret += solve((1 << 2), idx + 1);
    }
    else if (type == 1) {
        ret += solve(0, idx + 1);
        ret += solve(((1 << 1) | (1 << 2)), idx + 1);
    }
    else if (type == (1 << 1)) {
        ret += solve(1 | (1 << 2), idx + 1);
    }
    else if (type == (1 << 2)) {
        ret += solve(0, idx + 1);
        ret += solve((1 | (1 << 1)), idx + 1);
    }
    else if (type == (1 | (1 << 1))) {
        ret += solve(1 << 2, idx + 1);
    }
    else if (type == ((1 << 1) | (1 << 2))) {
        ret += solve(1, idx + 1);
    }
    else if (type == (1 | (1 << 2))) {
        ret += solve((1 << 1), idx + 1);
    }
    else if (type == (1 | (1 << 1) | (1 << 2))) {
        ret += solve(0, idx + 1);
    }

    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> n;

    cout << solve(0, 0);
}