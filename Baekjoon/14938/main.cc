#include<bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int n, m, r;

int ans = -INF;

vector<pair<int, int>> vec[101];
vector<int> value;

int dijkstra(int start) {
    vector<int> dist (n + 1, INF);
    priority_queue<pair<int, int>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()) {
        int cur = pq.top().second;
        int cost = -pq.top().first;

        pq.pop();

        for(int i = 0; i < vec[cur].size(); i++) {
            int next = vec[cur][i].first;
            int ncost = vec[cur][i].second;

            if(dist[next] > cost + ncost) {
                dist[next] = cost + ncost;
                pq.push({next, -dist[cur]});
            }
        }
    }

    int ret = 0;
    for(int i = 1; i <= n; i++) {
        if(dist[i] < m) {
            ret += value[i - 1];
        }
    }

    return ret;
}

int main() {
    cin >> n >> m >> r;

    for(int i = 0 ; i < n; i++) {
        int a;
        cin >> a;
        value.push_back(a);
    }

    for(int i = 0; i < r; i++) {
        int s, e, c;
        cin >> s >> e >> c;

        vec[s].push_back({e, c});
        vec[e].push_back({s, c});
    }

    for(int i = 1; i <= n; i++) {
        ans = max(ans, dijkstra(i));
    }

    cout << ans;
}