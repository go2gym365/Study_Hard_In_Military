#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> input;
int dp[10001][3];

//1: 안마심, 2:한번만 먹음 3:연속해서 먹음
int solve(int idx, int choice) {
    if(idx  == n + 1) return 0;

    int &ret = dp[idx][choice];

    if(ret != -1) return ret;
    
    ret = solve(idx+1, 0);
    if(choice == 0) ret = max(ret, solve(idx+1, 1) + input[idx]);
    if(choice == 1) ret = max(ret, solve(idx+1, 2) + input[idx]);

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));

    cin >> n;

    input.push_back(0);
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        input.push_back(a);
    }

    cout << solve(0, 0);
}