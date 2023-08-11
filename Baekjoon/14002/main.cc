#include<bits/stdc++.h>

using namespace std;

short n;

vector<short> vec;

short dp[1001][1001];
vector<short> trac;

short solve(short prev, short idx) {
    if(idx == n) return 0;
    short &ret = dp[prev][idx];
    if(ret != -1) return ret;

    ret = 0;

    for(short i = idx; i < n; i++) {
        if(prev < vec[i]) {
            trac.push_back(vec[i]);
            ret = max(ret, solve(vec[i], idx + 1) + 1);
        }
    }

    return ret;
}

short main() {
    memset(dp, -1, sizeof(dp));

    cin >> n;

    for(short i = 0; i < n; i++) {
        short a;
        cin >> a;

        vec.push_back(a);
    }

    short ans = solve(0, 0);

    cout << ans << "\n";
}