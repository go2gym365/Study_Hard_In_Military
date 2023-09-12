#include<bits/stdc++.h>
#include <string>

using namespace std;

int n;

vector<string> ans;

void solve(int calc, int cnt, string str) {
    if(cnt == n) {
        if(calc == 0) {
            ans.push_back(str);
            return;
        }
        return;
    }

    if(cnt == 0) {
        solve(calc + (cnt+1), cnt+1, str + to_string(cnt + 1));
        solve(calc + (cnt+1)*10 + (cnt+2), cnt + 2, str + to_string(cnt + 1) + ' ' + to_string(cnt + 2));
    }
    else {
        solve(calc + (cnt+1), cnt+1, str + '+' + to_string(cnt + 1));
        solve(calc - (cnt+1), cnt+1, str + '-' + to_string(cnt + 1));
    
        if(cnt + 2 <= n) solve(calc + (cnt+1)*10 + (cnt+2), cnt + 2, str + '+' + to_string(cnt + 1) + ' ' + to_string(cnt + 2));
        if(cnt + 2 <= n) solve(calc - (cnt+1)*10 - (cnt+2), cnt + 2, str + '-' + to_string(cnt + 1) + ' ' + to_string(cnt + 2));
    }
    


}

int main() {
    int t;
    cin >> t;

    while(t--) {
        cin >> n;

        solve(0, 0, "");

        sort(ans.begin(), ans.end());
        
        for(int i = 0; i < ans.size(); i++) {
            cout << ans[i] <<  '\n';
        }
        cout << '\n';

        ans.clear();        
    }
}