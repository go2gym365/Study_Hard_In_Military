#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int>> goods;
int dp[100001];

const int INF = -987654321;
int n, k;

int solve(int weight) {
    if(weight == k) return goods[weight].second;
    int &ref = dp[weight];
    if(ref != -1) return ref;
    ref = INF;

    
}

int main() {
    memset(dp, -1, sizeof(dp));
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        int w, v;
        cin >> w >> v;
        goods.push_back({w, v});
    }

    solve(0);
}