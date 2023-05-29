#include<bits/stdc++.h>
using namespace std;

const int INF = 987654321;

vector<pair<int, int>> v[801];
vector<int> dist(801, INF);

void dijkstra(int start) {
    priority_queue<pair<int, int>>pq;
    pq.push({0, start});

    while(!pq.empty()) {
        int here = pq.top().first;
        int cost = -pq.top().second;
        pq.pop();


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
    int N, E, v1, v2, res;
    cin >> N >> E;
    int stov1, stov2, v1tov2, v1toN, v2toN;
    while(E--) {
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

    res = min(res, stov1 + v1tov2 + v2toN);
    res = min(res, stov2 + v1tov2 + v1toN);
    if(v1tov2 == INF || res == INF) cout << -1;
    else cout << res;
}