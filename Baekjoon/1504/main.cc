#include <bits/stdc++.h>

using namespace std;

const int INF = numeric_limits<int>::max();

vector<pair<int, int>> v[801];
vector<int> dist(801, INF);

void dijkstra(int start) {
    dist.assign(801, INF);
    priority_queue<pair<int, int>>pq;
    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        
        if(dist[here] < cost) continue;

        for(int i = 0; i < v[here].size(); i++) {
            int there = v[here][i].first;
            int ncost = v[here][i].second + cost;

            if(dist[there] > ncost) {
                dist[there] = ncost;
                pq.push({-ncost, there});
            }
        }
    }
}

int main() {
    int N, E, v1, v2;
    int stov1, stov2, v1tov2, v1toN, v2toN;
    
    cin >> N >> E;

    for(int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    cin >> v1 >> v2;

    dijkstra(1);
    stov1 = dist[v1];
    stov2 = dist[v2];

    dijkstra(v1);
    v1tov2 = dist[v2];
    v1toN = dist[N];

    dijkstra(v2);
    v2toN = dist[N];

    int res = min((long long)stov2 + v1tov2 + v1toN, (long long)stov1 + v1tov2 + v2toN);
    
    if(res >= INF) cout << -1;
    else cout << res;

    return 0;
}