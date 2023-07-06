#include<bits/stdc++.h>

using namespace std;

int n, m;

vector<bool> num(10, false);

bool check(int now) {
    string s = to_string(now);
    for(int i = 0; i < s.length(); i++) {
        if(num[s[i] - 48]) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a;
        cin >> a;
        num[a] = true;
    }

    int ans = abs(n - 100);
    
    for(int i = 0; i <= 1000000; i++) {
        if(check(i)) {
            int res =  abs(n - i) + to_string(i).size();
            ans = min(ans, res);
        }
    }
    cout << ans;
}