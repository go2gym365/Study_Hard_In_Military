#include <bits/stdc++.h>

using namespace std;

map<string, bool> name;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n;
    char c;
    
    cin >> n >> c;
    
    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        
        if(!name[str]) {
            cnt++;
            if(c == 'Y') {
                if(cnt == 1) {
                    cnt = 0;
                    ans++;
                }
            }
            else if(c == 'F') {
                if(cnt == 2) {
                    cnt = 0;
                    ans++;
                }
            }
            else if(c == 'O') {
                if(cnt == 3) {
                    cnt = 0;
                    ans++;
                }
            }
            name[str] = true;
        }
        else {
            continue;
        }
    }
    
    cout << ans;
}
