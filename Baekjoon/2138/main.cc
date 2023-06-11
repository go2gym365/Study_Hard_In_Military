#include<bits/stdc++.h>

using namespace std;

string ex, user, temp;
int cnt = 0;
int ans = 987654321;
int n;

void lightOn(int idx) {
    if(idx > 0) temp[idx - 1] = (temp[idx - 1] == '0') ? '1' : '0';
    temp[idx] = (temp[idx] == '0') ? '1' : '0';
    if(idx < n - 1) temp[idx + 1] = (temp[idx + 1] == '0') ? '1' : '0';
}

void solve(int start) {
    temp = user;
    cnt = 0;
    if(start == 0) {
        temp[0] = (temp[0] == '0') ? '1' : '0';
        temp[1] = (temp[1] == '0') ? '1' : '0';
        ++cnt;
    }
    for(int i = 0; i < n; i++) {
        if(temp[i - 1] != ex[i-1]) {
            lightOn(i);
            ++cnt;
        }
    }
    if(temp == ex) 
        ans = min(ans, cnt);
}

int main() {
    cin >> n;
    cin >> user;
    cin >> ex;

    solve(1);
    solve(0);

    if(ans != 987654321) cout << ans;
    else cout << -1;
}