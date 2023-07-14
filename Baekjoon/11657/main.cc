#include<bits/stdc++.h>

using namespace std;

int n, m;
const int INF = 0x3f3f3f3f;

long long dist[501];
bool cycle;

vector<pair<int, int>> edge[501];

void bellman_ford() {
    for(int i = 1; i <= n; i++)
        dist[i] = INF;

    dist[1] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 0; k < edge[j].size(); k++) {
                int next = edge[j][k].first;
                int cost = edge[j][k].second;

                if(dist[j] != INF && dist[next] > dist[j] + cost) {
                    dist[next] = dist[j] + cost;
                    if(i == n) cycle = true; // n-1확인 후 한번 더 갱신되면 음의 사이클 들음
                }
            }
        }
    }
    if(cycle) cout << -1 << "\n";
    else {
        for(int i = 2; i <= n; i++) {
            cout << (dist[i] != INF ? dist[i] : -1) << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> m;

    for(int i = 0; i < m ; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        edge[a].push_back({b, c});
    }

    bellman_ford();
}