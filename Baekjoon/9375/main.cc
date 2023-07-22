#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        map<string, int> m;
        int n;
        cin >> n;

        for(int i = 0; i < n; i++) {
            string cat, name;
            cin >> name >> cat;

            if(m.find(cat) == m.end()) {
                m.insert({cat, 1});
            }
            else {
                m[cat]++;
            }
        }

        int ans = 1;

        for(auto a : m) {
            ans *= (a.second + 1);
        }

        cout << ans - 1 << "\n";
    }
}