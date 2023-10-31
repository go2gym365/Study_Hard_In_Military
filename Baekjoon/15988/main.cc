#include <iostream>
#include <cstring>

using namespace std;

long long dp[1000001];

long long solve(long long n) {
    if(n == 0) return 1;
    else if(n < 0) return 0;
    
    long long &ret = dp[n];
    
    if(ret != -1) return ret;
    
    ret = 0;
    
    ret += solve(n - 1);
    ret += solve(n - 2);
    ret += solve(n - 3);
    
    return ret %= 1000000009;
} 

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));
    
    int t;
    cin >> t;
    
    while(t--) {
        int num;
        cin >> num;
        
        cout << solve(num) << '\n';
    }
    
}
