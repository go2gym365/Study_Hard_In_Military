#include<bits/stdc++.h>
using namespace std;

const int INF = 987654321;

vector<pair<int, int>> v[100001];
vector<int> dist(1001, INF);

void dijkstra(int starts) {
    priority_queue<pair<int, int>> pq;
    dist[0] = 0;
    pq.push({0, starts});

    while(!pq.empty()) {
        int current = pq.top().second;
        int current_cost = -pq.top().first;
        pq.pop();

        if(dist[current] < current_cost) continue;

        for(int i = 0; i < v[current].size(); i++) {
            int n_node = v[current][i].second;
            int n_cost = current_cost + v[current][i].first;

            if(dist[n_node] > n_cost) {
                dist[n_node] = n_cost;
                pq.push({-n_cost, n_node});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    int starts, ends;

    cin >> N >> M;
    while(M--) {
        int start, end, cost;
        cin >> start >> end >> cost;
        v[start].push_back({cost, end});
    }
    cin >> starts >> ends;

    dijkstra(starts);

    cout << dist[ends];
}