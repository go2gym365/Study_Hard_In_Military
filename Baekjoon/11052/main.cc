#include <iostream>
#include <cstring>
using namespace std;

int n;
int cost[10001];
int dp[1001];

int solve(int amount) {
    if(amount == 0) return 0;
    int &ret = dp[amount];
    if(ret != -1) return ret;
    
    ret = 0;
    
    for(int i = 1; i <= amount; i++) {
        ret = max(ret, cost[i] + solve(amount - i));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));
    
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        cin >> cost[i];
    }
    
    cout << solve(n);
}
