#include<vector>
#include<cstring>
#include <iostream>
#include<algorithm>

using namespace std;

int n, m, k;
const int INF = 0x3f3f3f3f;

int dp[301][301];
int input[301][301];

int solve(int node, int cnt) {
    if(node != n && cnt == m) return -INF;
    if(node == n) return 0;
    
    int &ret = dp[node][cnt];
    
    if(ret != -1) return ret;
    
    ret = -INF;
    
    for(int i = node+1; i <= n; i++) {
        if(input[node][i]) {
            ret = max(ret, solve(i, cnt+1) + input[node][i]);
        }
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));
    
    cin >> n >> m >> k;
    
    for(int i = 0; i < k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        
        input[a][b] = max(input[a][b], c);
    }
    
    cout << solve(1, 1);
}
