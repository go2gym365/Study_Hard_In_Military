#include<bits/stdc++.h>

using namespace std;

map<string, string> Map;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        string site, pw;
        cin >> site >> pw;

        Map.insert({site, pw});
    }

    for(int i = 0; i < m; i++) {
        string str;
        cin >> str;

        cout << Map[str] << "\n";
    }
}