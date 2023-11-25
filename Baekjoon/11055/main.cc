#include <bits/stdc++.h>

using namespace std;

int n;

vector<int> input;

//증가하는 부분수열의 합
int dp[1001][1001];

int solve(int idx, int choice) {
    if(idx == n) return 0;
    
    int &ret = dp[idx][choice];
    
    if(ret != -1) return ret;
    ret = 0;
    
    if(input[idx] > choice) {
        ret = max(ret, solve(idx+1, input[idx]) + input[idx]);
    }
    
    ret = max(ret, solve(idx+1, choice));
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        
        input.push_back(a);
    }
    
    int ans = 0;
    
    for(int i = 0; i < n; i++) {
        ans = max(ans, solve(i, 0));
    }
    
    cout << ans;
}
