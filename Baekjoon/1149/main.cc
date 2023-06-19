#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> color[1001];
int dp[1001][4];

int solve(int num, int col) {
    if(num == n) return 0;
    int &sum = dp[num][col];
    if(sum != -1) return sum;
    sum = 987654321;

    if(col == 0) {
        sum = min(sum, solve(num + 1, 1) + color[num][1]);
        sum = min(sum, solve(num + 1, 2) + color[num][2]);
    }
    if(col == 1) {
        sum = min(sum, solve(num + 1, 0) + color[num][0]);
        sum = min(sum, solve(num + 1, 2) + color[num][2]);
    }
    if(col == 2) {
        sum = min(sum, solve(num + 1, 0) + color[num][0]);
        sum = min(sum, solve(num + 1, 1) + color[num][1]);
    }
    if(col == 3) {
        sum = min(sum, solve(num + 1, 0) + color[num][0]);
        sum = min(sum, solve(num + 1, 1) + color[num][1]);
        sum = min(sum, solve(num + 1, 2) + color[num][2]);
    }

    return sum;
}

int main() {
    memset(dp, -1, sizeof(dp));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++) {
        int r, g, b;
        cin >> r >> g >> b;
        color[i].push_back(r);
        color[i].push_back(g);
        color[i].push_back(b);
    }

    cout << solve(0, 3);
}