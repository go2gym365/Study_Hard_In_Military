#include <bits/stdc++.h>

using namespace std;

int n, m, w;
const int INF = 0x3f3f3f3f;

vector<pair<int, int>> adj[501];

void bellman(int start, int target) {
    //모든 정점까지의 최단거리 상한
    vector<int> upper(501, INF);
    bool update = false;
    upper[start] = 0;

    for (int iter = 0; iter < n; ++iter) {
        update = false;
        for(int here = 1; here <= n; ++here) {
            for(int i = 0; i < adj[here].size(); i++) {
                int cost = adj[here][i].first;
                int there = adj[here][i].second;
                if(upper[there] > upper[here] + cost) {
                    upper[there] = upper[here] + cost;
                    update = true;
                }
            }
        }
        if(!update) {
            cout << "NO" <<"\n";
            break;
        }
    }
    if(update)
        cout << "YES" << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n >> m >> w;

        for (int i = 0; i <= n; i++) {
            adj[i].clear();
        }

        for (int i = 0; i < m; i++) {
            int s, e, t;
            cin >> s >> e >> t;

            adj[s].push_back({t, e});
            adj[e].push_back({t, s});
        }

        for (int i = 0; i < w; i++) {
            int s, e, t;
            cin >> s >> e >> t;

            adj[s].push_back({-t, e});
        }

        bellman(1, n);
    }
}