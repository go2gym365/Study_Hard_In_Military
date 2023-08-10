#include<bits/stdc++.h>

using namespace std;

int n;
const int INF = 987654321;

int dp[1000001];
int before[1000001];

int solve(int num) {
    int &ret = dp[num];
    if(num == 1) return 0;
    if(ret != -1) return ret;
    ret = INF;
    
    ret = min(ret, solve(num - 1) + 1);
    before[num] = num - 1;

    if(num % 3 == 0) {
        ret = min(ret, solve(num / 3) + 1);
        before[num] = num / 3;
    }

    if(num % 2 == 0) {
        ret = min(ret, solve(num / 2) + 1);
        before[num] = num / 2; 
    }
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    memset(dp, -1, sizeof(dp));
    memset(before, 0, sizeof(before));

    cin >> n;

    cout << solve(n) << "\n";

    while(n != 0) {
        cout << n << " ";
        n = before[n];
    }
}