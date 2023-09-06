#include<bits/stdc++.h>

using namespace std;

int n, m;

int dp[41][41][3];

vector<int> vip;

int solve(int idx, int pointer, int prevC) {
    if(idx == n + 1) return 1;
    int &ret = dp[idx][pointer][prevC];
    if(ret != -1) return ret;

    //처음 시작
    if(prevC == -1) {
        if(idx + 1 == vip[pointer]) {
            ret += solve(idx + 1, pointer + 1, 0);
        }
        else {
            ret += solve(idx + 1, pointer, 0);
            ret += solve(idx + 1, pointer, 1);
        }
    }
    //이전에 자신의 자리에 앉음
    else if(prevC == 0) {
        if(idx + 1 == vip[pointer]) {
            ret += solve(idx + 1, pointer + 1, 0);
        }
        else {
            ret += solve(idx + 1, pointer, 0);
            ret += solve(idx + 1, pointer, 1);
        }
    }
    //이전에 자기 자리 안앉음
    else if(prevC == 1) {
        if(idx + 1 == vip[pointer]) {
            ret += solve(idx + 1, pointer + 1, 0);
        }
        else {
            ret += solve(idx + 1, pointer, 0);
        }
    }
    return ret;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a;
        cin >> a;
        vip.push_back(a);
    }

    cout << solve(0, 0, -1);
}