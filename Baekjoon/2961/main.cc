#include <bits/stdc++.h>

using namespace std;

vector<pair<long long, long long>> taste;

long long ans = LLONG_MAX;
long long n;

void solve(long long idx, long long sour, long long bitter) {
    if(idx == n) return;
    if(sour == 0) {
        ans = min(ans, abs(taste[idx].first - taste[idx].second));
        solve(idx+1, taste[idx].first, taste[idx].second);
    }
    else {
        ans = min(ans, abs(sour*taste[idx].first - (bitter+taste[idx].second)));
        solve(idx+1, sour, bitter);
        solve(idx+1, sour*taste[idx].first, bitter+taste[idx].second);
    }
    
    return;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        long long sour, bitter;
        cin >> sour >> bitter;
        
        taste.push_back({sour, bitter});
    }
    
    for(int i = 0; i < n; i++) {
        solve(i, 0, 1);
    }
    
    cout << ans;
}
