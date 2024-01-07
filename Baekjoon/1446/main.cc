#include <bits/stdc++.h>

using namespace std;

int n, d;

vector<pair<int, int>> arr[10001];
int dp[10001];

int solve(int location) {
    if(location == d) return 0;
    
    int &ret = dp[location];
    if(ret != -1) return ret;
    
    ret = 0x3f3f3f3f;
    
    if(!arr[location].empty()) {
        for(int i = 0; i < arr[location].size(); i++) {
            if(arr[location][i].first > d) continue;
            ret = min(ret, solve(arr[location][i].first) + arr[location][i].second);
        }
    }
    
    ret = min(ret, solve(location+1)+1);
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));
    
    cin >> n >> d;
    
    for(int i = 0; i < n; i++) {
        int s, e, leng;
        cin >> s >> e >> leng;  
        
        arr[s].push_back({e, leng});
    }
    
    cout << solve(0);
}