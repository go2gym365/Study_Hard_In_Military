#include<bits/stdc++.h>

using namespace std;

map<string, bool> M;
vector<string> ans;

int n, m;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        M.insert({s, true});
    }

    for(int i = 0; i < m; i++) {
        string s;
        cin >> s;

        if(M[s]) ans.push_back(s);
    }

    sort(ans.begin(), ans.end());
    
    cout << ans.size() << "\n";

    for(auto s : ans) {
        cout << s << "\n";
    }
}