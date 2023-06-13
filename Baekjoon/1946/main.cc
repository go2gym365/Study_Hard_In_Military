#include<bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;

    while(T--) {
        vector<pair<int, int>> v;
        int n;
        int cnt = 0;
        int IScore = 987654321;
        cin >> n;
        for(int i = 0; i < n; i++) {
            int r, I;
            cin >> r >> I;
            v.push_back({r, I});
        }

        sort(v.begin(), v.end());

        for(int j = 0; j < n; j++) {
            if(IScore > v[j].second) {
                ++cnt;
                IScore = v[j].second;
            }
        }

        cout << cnt << "\n";
    }
}