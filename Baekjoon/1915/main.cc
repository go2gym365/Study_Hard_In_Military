#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
string input[1001];
int dp[1001][1001];
int maxLen = 0;

int solve(int y, int x) {
    if(y == n || x == m) return 0;
    int &ret = dp[y][x];
    if(ret != -1) return ret;
    if(input[y][x] == '0') return ret = 0;
    
    ret = min({solve(y+1,x), solve(y+1, x+1), solve(y,x+1)}) + 1;
    maxLen = max(maxLen, ret);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            solve(i, j);
        }
    }
    
    cout << maxLen*maxLen;
}
