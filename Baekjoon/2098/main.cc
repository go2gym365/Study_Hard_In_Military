#include<bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int n;
int dp[16][1<<16]; //2^16
int input[16][16];

int dfs(int cur, int vis) {
    //기저 조건
    if(vis == (1 << n) - 1) {
        if(input[cur][0] == 0) {
            return INF;
        }
        return input[cur][0];
    }

    int &ret = dp[cur][vis];

    if(ret != -1) return ret;

    ret = INF;

    for(int i = 0; i < n; i++) {
        if(input[cur][i] == 0) //길이 없으면
            continue;
        if((vis & (1<<i)) == (1<<i))
            continue;
        ret = min(ret, dfs(i, vis | 1<<i) + input[cur][i]);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> input[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    cout << dfs(0, 1);
    
}