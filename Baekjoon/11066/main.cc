#include <bits/stdc++.h>

using namespace std;

int n;
const int INF = 0x3f3f3f3f;

int file[501];
int tempSum[501][501];
int dp[501][501];

int solve(int left, int right) {
    if(left == right) return 0;
    
    int &ret = dp[left][right];
    if(ret != -1) return ret;
    
    ret = INF;
    
    for(int i = left; i < right; i++) {
        ret = min(ret, solve(left, i) + solve(i+1, right));
    }
    return ret += tempSum[left][right];
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    
    while(t--) {
        memset(file, 0, sizeof(file));
        memset(dp, -1, sizeof(dp));
        memset(tempSum, 0, sizeof(tempSum));
        
        cin >> n;
        
        for(int i = 1; i <= n; i++) {
            cin >> file[i];
        }
        
        for(int i = 1; i <= n; i++) {
            tempSum[i][i] = file[i];
        }
        
        for(int i = 1; i <= n; i++) {
            for(int j = i+1; j <= n; j++) {
                tempSum[i][j] = tempSum[i][j-1] + file[j];
            }
        }
        
        cout << solve(1, n) << "\n";
    }
}