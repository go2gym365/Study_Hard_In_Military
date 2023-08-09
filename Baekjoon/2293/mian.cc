#include<bits/stdc++.h>

using namespace std;

int n, k;

vector<int> vec;
int dp[10001][101];

int solve(int sum, int idx) {
    int &ret = dp[sum][idx];
    if(sum == k) return 1;
    if(sum > k) return 0;
    if(ret != 0) return ret;

    ret = 0;

    for(int i = idx; i < n; i++) {
        ret += solve(sum + vec[i], i);
    }
    return ret;
}

// int solve(int sum, int idx) {
//     int ret = 0;
//     if(sum == k) return 1;
//     if(sum > k) return 0;

//     for(int i = idx; i < n; i++) {
//         ret += solve(sum + vec[i], i);
//     }
//     return ret;
// }

int main() {
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;

        vec.push_back(a);
    }

    cout << solve(0, 0);
}