#include<bits/stdc++.h>

using namespace std;

int n;
vector<int>input [1001];
int dp[1001][4][3];

int solve(int idx, int prev, int first) {
    if(idx == n) return 0;
    int &ret = dp[idx][prev][first];
    if(ret != -1) return ret;
    ret = 987654321;

    if(idx == n - 1) {
        if(prev == 0) {
            if(first == 1) {
                ret = min(ret, solve(idx + 1, 2, first) + input[idx][2]);
            }
            else if(first == 2) {
                ret = min(ret, solve(idx + 1, 1, first) + input[idx][1]);
            }
        }
        else if(prev == 1) {
            if(first == 0) {
                ret = min(ret, solve(idx + 1, 2, first) + input[idx][2]);
            }
            else if(first == 2) {
                ret = min(ret, solve(idx + 1, 0, first) + input[idx][0]);
            }
        }
        else if(prev == 2) {
            if(first == 1) {
                ret = min(ret, solve(idx + 1, 0, first) + input[idx][0]);
            }
            else if(first == 0) {
                ret = min(ret, solve(idx + 1, 1, first) + input[idx][1]);
            }
        }
    } 
    else {
        if (prev == 0) {
            ret = min(ret, solve(idx + 1, 1, first) + input[idx][1]);
            ret = min(ret, solve(idx + 1, 2, first) + input[idx][2]);
        } 
        else if (prev == 1) {
            ret = min(ret, solve(idx + 1, 0, first) + input[idx][0]);
            ret = min(ret, solve(idx + 1, 2, first) + input[idx][2]);
        } 
        else if (prev == 2) {
            ret = min(ret, solve(idx + 1, 0, first) + input[idx][0]);
            ret = min(ret, solve(idx + 1, 1, first) + input[idx][1]);
        } 
        else if (prev == 3) {
            ret = min(ret, solve(idx + 1, 0, 0) + input[idx][0]);
            ret = min(ret, solve(idx + 1, 1, 1) + input[idx][1]);
            ret = min(ret, solve(idx + 1, 2, 2) + input[idx][2]);
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));

    cin >> n;

    for(int i = 0; i < n; i++) {
        int r, g, b;
        cin >> r >> g >> b;

        input[i].push_back(r);
        input[i].push_back(g);
        input[i].push_back(b);
    }

    cout << solve(0, 3, 0);
}