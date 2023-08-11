#include<bits/stdc++.h>

using namespace std;

int n;

vector<int> vec;
int dp[1001][1001];

int solve(int prev, int cnt) {
    if(cnt == n) return 0;
    int &ret = dp[prev][cnt];
    if(ret != -1) return ret;
    ret = 0;


    for(int i = cnt; i < n; i++) {
        if(prev < vec[i]) {
            ret += max(ret, solve(vec[i], i + 1) + 1);
        }
    }

    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> n;

    for(int i = 0; i < n; i++) {
        int a; cin >> a;

        vec.push_back(a);
    }

    cout << solve(0, 0);
}