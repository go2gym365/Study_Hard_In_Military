#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int>> goods;
int dp[101][100001];
int n, k;

int solve(int weight, int cnt) {
    if(cnt == n) return 0;
    int &ret = dp[cnt][weight];
    if(ret != -1) return ret;
    ret = 0;
    //ret 가치 최댓값 / 무게 합 / 몇번 상품

    if(goods[cnt].first + weight <= k) {
        ret = max(ret, solve(weight + goods[cnt].first, cnt + 1) + goods[cnt].second);
    }
    ret = max(ret, solve(weight, cnt + 1));

    return ret;
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

    cout << solve(0, 0);
}