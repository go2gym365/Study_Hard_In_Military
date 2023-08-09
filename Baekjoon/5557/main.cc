#include<bits/stdc++.h>

using namespace std;

int n;

vector<int> vec;

long long dp[30][101];


long long solve(int sum, int cnt) {
    if (cnt == n - 1 && sum == vec[n - 1]) {
        return 1;
    }
    else if(cnt == n - 1 && sum != vec[n - 1])
        return 0;

    if(sum > 20 || sum < 0) return 0;

    long long &ret = dp[sum][cnt];
    if(ret != -1) return ret;
    ret = 0;

    ret += solve(sum + vec[cnt], cnt + 1);
    ret += solve(sum - vec[cnt], cnt + 1);

    return ret;
}

// int solve(int sum, int cnt) {
//     int ret = 0;
//     if (cnt == n - 1 && sum == vec[n - 1]) {
//         return 1;
//     }
//     else if(cnt == n - 1 && sum != vec[n - 1])
//         return 0;

//     if(sum > 20 || sum < 0) return 0;

//     ret += solve(sum + vec[cnt], cnt + 1);
//     ret += solve(sum - vec[cnt], cnt + 1);

//     return ret;
// }

int main() {
    memset(dp, -1, sizeof(dp));

    cin >> n;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;

        vec.push_back(a);
    }

    cout << solve(vec[0], 1);
}