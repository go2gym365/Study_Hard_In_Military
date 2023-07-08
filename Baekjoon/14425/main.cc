#include<bits/stdc++.h>

using namespace std;

unordered_map<string, bool> M;

int n, m;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    int cnt = 0;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        M.insert({s, true});
    }

    for(int i = 0; i < m; i++) {
        string s;
        cin >> s;

        if(M[s]) cnt++;
    }

    cout << cnt;
}