#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    string str;
    cin >> str;

    stack<char> sta;
    int cnt = 0;

    for(int i = 0; i < n; i++) {
        while(!sta.empty() && k > cnt && sta.top() < str[i]) {
            cnt++;
            sta.pop();
        }
        sta.push(str[i]);
    }
    while(cnt < k) {
        cnt++;
        sta.pop();
    }

    vector<char> ans;
    while(!sta.empty()) {
        ans.push_back(sta.top());
        sta.pop();
    }

    for(int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i];
    }
}