#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    
    stack<pair<int, int>> sta;
    
    for(int i = 1; i <= n; i++) {
        int input;
        cin >> input;
        
        if(sta.empty()) {
            cout << 0 << ' ';
            sta.push({i, input});
        }
        else {
            while(!sta.empty()) {
                if(sta.top().second > input) {
                    cout << sta.top().first << ' ';
                    break;
                }
                else {
                    sta.pop();
                }
            }
            
            if(sta.empty()) {
                cout << 0 << ' ';
            }
            
            sta.push({i, input});
        }
    }
}