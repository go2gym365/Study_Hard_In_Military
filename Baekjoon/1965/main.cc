#include<bits/stdc++.h>
//LIS Algorithm
using namespace std;

int dp[1001][1001];
vector<int> vec;

int n;

int solve(int prev, int cur) {
    if (cur == n) return 0;
    int ret = 0;
    for(int i=cur; i<n; i++) {
        if (prev < vec[i]) {
            cout << vec[i] << " ";
            ret = max(ret, solve(vec[i], i+1) + 1);
        }
    }
    cout << endl;
    return ret;
}

int Solved(int prev, int cur) {
    int &ret = dp[prev][cur];
    if (cur == n) return 0;
    if(ret != 0) return ret;
    ret = 0;
    for(int i = cur; i < n; i++) {
        if(prev < vec[i]) {
            ret = max(ret, Solved(vec[i], i + 1) + 1);
        }
    }
    return ret;
}

int main() {
    memset(dp, 0, sizeof(dp));

    cin >> n;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;

        vec.push_back(a);
    }

    cout << Solved(0, 0);

    return 0;
}