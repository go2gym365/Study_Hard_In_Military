#include<bits/stdc++.h>

using namespace std;

map<string, int> m;

int main() {
    int n;
    int cnt = 0;

    cin >> n;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        m[s]++;
    }

    for(auto str : m) 
        cnt = max(cnt, str.second);

    for(auto str : m) {
        if(str.second == cnt) {
            cout << str.first;
            return 0;
        }
    }
}