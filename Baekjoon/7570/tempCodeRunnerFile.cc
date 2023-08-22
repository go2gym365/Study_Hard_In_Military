#include<bits/stdc++.h>

using namespace std;

int n;

vector<int> vec;

int dp[1000001][1000001];

int solve(int prev, int cur) {
    if(cur == n) return 0;
    int &ret = dp[prev][cur];
    if(ret != -1) return ret;

    ret = 0;

    for(int i = 0; i < n; i++) {
        for(int j = cur; j < n; j++) {
            if(vec[prev] < vec[j]) {
                ret = max(ret, solve(vec[j], i + 1) + 1);
            }
        }
    }
    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));

    cin >> n;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        vec.push_back(a);
    }
    
    cout << n - solve(0, 0);
}