#include<bits/stdc++.h>

using namespace std;

int n, m;
int s, e;
int cnt = 0;
int inDegree[10001];
int dist[10001];
bool vis[10001];
vector<pair<int, int>> graph[10001];
vector<pair<int, int>> revGraph[10001];

void BFS() {
    queue<pair<int, int>> q;
    q.push({s, 0});

    while(!q.empty()) {
        int cur = q.front().first;
        int curCost = q.front().second;
        q.pop();

        for(int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            int nCost = graph[cur][i].second;

            dist[next] = max(dist[next], curCost + nCost);
            inDegree[next]--;

            if(!inDegree[next]) q.push({next, dist[next]});
        }
    }
}

void revBFS() {
    queue<int> q;
    q.push(e);
    vis[e] = true;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int i = 0; i < revGraph[cur].size(); i++) {
            int next = revGraph[cur][i].first;
            int ncost = revGraph[cur][i].second;

            if(dist[cur] - ncost == dist[next]) {
                cnt++;
                if(!vis[next]) {
                    vis[next] = true;
                    q.push(next);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        revGraph[b].push_back({a, c});
        inDegree[b]++;
    }

    cin >> s >> e;

    BFS();
    revBFS();

    cout << dist[e] << "\n" << cnt;
}