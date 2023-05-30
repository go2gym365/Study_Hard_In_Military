#include<bits/stdc++.h>
using namespace std;

const int INF = 987654321;

vector<pair<int, int>> v[801];
vector<int> dist(801, INF);

void dijkstra(int start) {
    //dist.assign(dist.begin(), dist.end());
    priority_queue<pair<int, int>>pq;
    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        
        if(dist[here] < cost) continue;

        for(int i = 0; i < v[here].size(); i++) {
            int there = v[here][i].second;
            int ncost = v[here][i].first + cost;

            if(dist[there] > ncost) {
                dist[there] = ncost;
                pq.push({-ncost, there});
            }
        }
    }
}

int main() {
    int N, E, v1, v2, res = 0;
    cin >> N >> E;
    int stov1, stov2, v1tov2, v1toN, v2toN;
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

    res = min(INF, stov1 + v1tov2 + v2toN);
    res = min(res, stov2 + v1tov2 + v1toN);
    
    if(v1tov2 == INF || res == INF) cout << -1;
    else cout << res;
}