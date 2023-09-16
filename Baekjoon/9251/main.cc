#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];
string s1, s2;

int solve(int p, int q) {
    if(p < 0 || q < 0) return 0;

    int &ret = dp[p][q];
    if(ret != -1) return ret;
    
    ret = 0;

    if(p >= 0)
        ret = max(ret, solve(p -1, q));
    
    if(s1[p] == s2[q])
        ret = max(ret, solve(p-1, q-1) +1);
    
    if(q >= 0) 
        ret = max(ret, solve(p, q-1));
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    memset(dp, -1, sizeof(dp));

    cin >> s1 >> s2;

    cout << solve(s1.length() - 1, s2.length() - 1);
}