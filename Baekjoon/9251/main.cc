#include <bits/stdc++.h>

using namespace std;

int n, m, w;
const int INF = 0x3f3f3f3f;

vector<pair<int, int>> vec[501];
vector<int> dist(501, INF);

int main() {
    cin >> n >> m >> w;
    int t;
    cin >> t;
    while (t--) {

        for (int i = 0; i < m; i++) {
            int s, e, c;
            cin >> s >> e >> c;

            vec[s].push_back({c, e});
            vec[e].push_back({c, s});
        }
    }

    
}