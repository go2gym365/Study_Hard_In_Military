#include<bits/stdc++.h>

using namespace std;

int n;
const int INF = -987654321;

vector<int> vec;
int dp[1000001];

// int solve(int idx) {
//     int &ret = dp[idx];
//     if(idx == n) return 0;
//     if(ret != 0) return ret;

//     ret = INF;

//     for(int i = 0; i < n; i++) {
//         for(int j = i + 1; j < n; j++) {
//             ret = max(ret, vec[i] + solve(idx + j));
//         }
//     }
// }

int ans = -INF;

int solve(int idx) {
    for(int i = 0; i < n; i++) {
        int temp = vec[i];
        for(int j = i; j < n; j++) {
            temp = max(temp, temp + vec[i]);
            
        }
    }
}

int main() {
    memset(dp, 0, sizeof(dp));

    cin >> n;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        vec.push_back(a);
    }

    solve(0);
}