#include<bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
int dist[10001];
vector<pair<int, int>> input[10001];

int n, d, c;

void dijkstra() {
    memset(dist, INF, sizeof(dist));

    priority_queue<pair<int, int>> pq;

    dist[c] = 0;

    pq.push({0, c});

    while(!pq.empty()) {
        int cur = pq.top().second;
        int cost = -pq.top().first;

        pq.pop();

        if(dist[cur] < cost) continue;

        for(int i = 0; i < input[cur].size(); i++) {
            int next = input[cur][i].second;
            int ncost = input[cur][i].first + cost;

            if(dist[next] > ncost) {
                dist[next] = ncost;
                pq.push({-ncost, next});
            }
        }
    }

    int infectCnt = 0;
    int ans = 0;

    for(int i = 1; i <= n; i++) {
        if(dist[i] != INF) {
            infectCnt++;
            ans = max(ans, dist[i]);
        }
    }
    cout << infectCnt << " " << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--) {
        for(int i = 0; i < 10001; i++) {
            input[i].clear();
        }
        cin >> n >> d >> c;

        for(int i = 0; i < d; i++) {
            int a, b, s;
            cin >> a >> b >> s;

            input[b].push_back({s, a});
        }

        
        dijkstra();
    }
}