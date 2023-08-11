#include<bits/stdc++.h>

using namespace std;

int n;

vector<int> vec;

int dp[1001][1001];
int before[1001][1001];

int solve(int prev, int idx) {
    if(idx == n) return 0;
    int &ret = dp[prev][idx];
    if(ret != -1) return ret;

    ret = 0;

    for(int i = idx; i < n; i++) {
        if(prev < vec[i]) {
            before[vec[i]][]
            ret = max(ret, solve(vec[i], idx + 1) + 1);
        }
    }
}

int main() {
    memset(dp, -1, sizeof(dp));

    cin >> n;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;

        vec.push_back(a);
    }

    solve(0, 0);
}