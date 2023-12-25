#include <bits/stdc++.h>

using namespace std;

int n;

int input[1001];
int dp[1001][1005][2];

int solve(int idx, int prevSelect, int turnCheck) {
    if(idx == n) return 0;
    
    int &ret = dp[idx][prevSelect][turnCheck];
    if(ret != -1) return ret;
    
    ret = 0;
    
    //오름차순일때
    if(turnCheck == 0) {
        if(prevSelect < input[idx]) {
            //현재 선택
            ret = max(ret, solve(idx+1, input[idx], turnCheck)+1);
        }
        //이번에 내림차순으로 변경하고 선택
        else if(prevSelect > input[idx]) {
            ret = max(ret, solve(idx+1, input[idx], 1)+1);
        }
    }
    else {
        if(prevSelect > input[idx]) {
            ret = max(ret, solve(idx+1, input[idx], turnCheck)+1);
        }
    }
    ret = max(ret, solve(idx+1, prevSelect, turnCheck));
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));
    
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int ans = max(solve(0, 0, 0), solve(0, 1002, 1));
    cout << ans;
}
