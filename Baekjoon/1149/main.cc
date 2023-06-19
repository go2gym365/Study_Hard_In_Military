#include<bits/stdc++.h>

using namespace std;

int n;

vector<int> color[1001];

int dp[1001][3];

int solve(int num, int col) {
    if(num == n) return 0;
    int &sum = dp[num][col];
    if(sum != -1) return sum;
    sum = 0;

    if(col == 0) {
        sum += solve(num + 1, 1);
        sum += solve(num + 1, 2);
        sum += solve(num + 1, 3);
    }
    if(col == 1) {
        sum += solve(num + 1, 2);
        sum += solve(num + 1, 3);
    }
    if(col == 2) {
        sum += solve(num + 1, 1);
        sum += solve(num + 1, 2);
        sum += solve(num + 1, 3);
    }
    if(col == 3) {
        sum += solve(num + 1, 1);
        sum += solve(num + 1, 2);
        sum += solve(num + 1, 3);
    }
}

int main() {
    memset(dp, -1, sizeof(dp));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    for(int i = 0; i < n; i++) {
        int r, g, b;
        cin >> r >> g >> b;
        color[i].push_back(r);
        color[i].push_back(g);
        color[i].push_back(b);
    }

    solve(1, 0);
}