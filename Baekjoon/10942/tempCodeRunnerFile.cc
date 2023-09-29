#include<bits/stdc++.h>

using namespace std;

int dp[2001][2001];
vector<int> input;
int n;

int solve(int start, int end) {
    if(start <= end) return 1;

    int &ret = dp[start][end];
    if(ret != -1) return ret;

    if(input[start] != input[end]) return 0;

    ret = solve(start + 1, end - 1);

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    memset(dp, -1, sizeof(dp));
    cin >> n;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        input.push_back(a);
    }

    //solve(0, n - 1);

    int num;
    cin >> num;

    for(int i = 0; i < num; i++) {
        int a, b;
        cin >> a >> b;

        cout << solve(a-1, b-1) << "\n";
    }
}