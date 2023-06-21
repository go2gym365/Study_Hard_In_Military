#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> ads;
int dp[21][1001];

int c, n;

// ret : 돈의 최솟값,

int solve(int visiter, int num)
{
    if (visiter >= c) return 0;
    if(num >= n) return 1000000;
    int &ret = dp[num][visiter];
    if (ret != -1) return ret;
    ret = 987654321;

    int mul = 0;
    while(visiter + ads[num].second * mul < c) {
        ret = min(ret, solve(ads[num].second * mul + visiter, num+1) + ads[num].first * mul);
        ++mul;
    }
    ret = min(ret, solve(ads[num].second * mul + visiter, num+1) + ads[num].first * mul);

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> c >> n;

    for (int i = 0; i < n; i++)
    {
        int cost, cust;
        cin >> cost >> cust;

        ads.push_back({cost, cust});
    }

    cout << solve(0, 0);
}