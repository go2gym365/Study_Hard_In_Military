#include <iostream>
#include <cstring>
using namespace std;

int n;
int dp[100001][3];

int solve(int idx, int prev) {
    if(idx == n) return 1;
    int &ret = dp[idx][prev];
    
    if(ret != -1) return ret;
    
    ret = 0;
    
    
        if(prev == 0) {
            ret += solve(idx+1, 0);
            ret += solve(idx+1, 1);
            ret += solve(idx+1, 2);
        }
        else if(prev == 1) {
            ret += solve(idx+1, 0);
            ret += solve(idx+1, 2);   
        }
        else if(prev == 2) {
            ret += solve(idx+1, 0);
            ret += solve(idx+1, 1);
        }
    
    
    return ret %= 9901;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    
    cout << solve(0, 0);
}
