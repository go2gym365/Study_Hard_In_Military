#include<bits/stdc++.h>

using namespace std;

int n;

vector<int> vec;

int dp[1000001];

/*int solve() {
    for(int i = 0; i < n; i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if(vec[j] < vec[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return dp[n - 1];
}*/

int solve(int left)

int main() {
    memset(dp, -1, sizeof(dp));

    cin >> n;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        vec.push_back(a);
    }
    
    cout << n - solve();
}