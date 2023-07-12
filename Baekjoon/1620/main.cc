#include<bits/stdc++.h>

using namespace std;

unordered_map<string, string> m;

int main() {
    ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
    int n, cur;
    cin >> n >> cur;
    
    for(int i = 1; i <= n; i++) {
        string str;

        cin >> str;

        m.insert({str, to_string(i)});
        m.insert({to_string(i), str});
    }

    for(int i = 0; i < cur; i++) {
        string s;
        cin >> s;
        cout << m[s] << "\n";
    }
}