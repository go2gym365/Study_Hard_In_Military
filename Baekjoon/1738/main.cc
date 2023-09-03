#include <bits/stdc++.h>

using namespace std;

int n, m;
const int INF = 0x3f3f3f3f;

vector<pair<int, int>> adj[101]; //벨만-포드 돌기위해 정보 저장
vector<int> rev_adj[101]; //BFS로 연결되어있는지 확인하기 위해 노드 정보 저장
int dist[101]; //최단거리 저장
int trace[101]; //경로를 확인하기 위해
bool vis[101]; //BFS에서 중복 방지 방문 배열
bool check = false; //음수사이클 체크

void bellman(int start, int end) {
    memset(dist, INF, sizeof(dist));
    dist[start] = 0;

    for (int iter = 0; iter < n; ++iter) {
        for (int here = 1; here <= n; ++here) {
            if (dist[here] == INF) continue;
            
            for (auto &a : adj[here]) {
                int there = a.first;
                int cost = a.second;
                if (dist[there] > dist[here] + cost) {
                    dist[there] = dist[here] + cost;
                    trace[there] = here;
                    //
                    if (iter == n - 1 && vis[there])
                        check = true;
                }
            }
        }
    }
}

void BFS() {    
    queue<int> q;
    q.push(n);
    vis[n] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < rev_adj[cur].size(); i++) {
            int next = rev_adj[cur][i];
            if (vis[next]) continue;
            vis[next] = true;
            q.push(next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, -w});
        rev_adj[v].push_back(u);
    }

    BFS();

    bellman(1, n);

    if (check) {
        cout << -1;
    } else {
        vector<int> tra;
        int tr = n;
        while (tr >= 1) {
            tra.push_back(tr);
            tr = trace[tr];
        }
        
        for(int i = tra.size() - 1; i >= 0; i--) {
            cout << tra[i] << " ";
        }
    }
}