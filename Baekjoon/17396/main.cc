#include<bits/stdc++.h>

using namespace std;

long long n, m;
const long long INF = LLONG_MAX;

long long dist[100001];
vector<pair<long long, long long>> graph[100001];
bool sight[100001];


void dijkstra() {
    priority_queue<pair<long long, long long>> pq;
    
    dist[0] = 0;
    pq.push({0, 0});
    
    while(!pq.empty()) {
        long long cur = pq.top().second;
        long long cost = -pq.top().first;
        
        pq.pop();
        
        if(dist[cur] < cost) continue;
        
        for(int i = 0; i < graph[cur].size(); i++) {
            long long next = graph[cur][i].first;
            long long nCost = cost + graph[cur][i].second;
            
            if(sight[next] && next != n-1) continue;
            
            if(dist[next] > nCost) {
                dist[next] = nCost;
                pq.push({-nCost, next});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for(int i = 0; i < 100001; i++) {
        dist[i] = INF;
    }
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        cin >> sight[i];
    }
    
    for(int i = 0; i < m; i++) {
        long long start, end, cost;
        cin >> start >> end >> cost;
        
        graph[start].push_back({end, cost});
        graph[end].push_back({start, cost});
    }
    
    dijkstra();
    
    if(dist[n-1] == INF) cout << -1;
    else cout << dist[n-1];
}