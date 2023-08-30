#include<bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int n, m;
int Start, End;

vector<pair<int, int>> vec[1001];
vector<int> dist(1001, INF);
vector<int> tra;
int trace[1001];

void dijkstra() {
    priority_queue<pair<int, int>> pq;

    dist[Start] = 0;
    pq.push({Start, 0});

    while(!pq.empty()) {
        int cur = pq.top().first;
        int cost = -pq.top().second;
        pq.pop();

        if(cost > dist[cur]) continue;

        for(int i = 0; i < vec[cur].size(); i++) {
            int next = vec[cur][i].first;
            int ncost = vec[cur][i].second;
            
            if(dist[next] > cost + ncost) {
                trace[next] = cur;
                dist[next] = cost + ncost;
                pq.push({next, -dist[next]});
            }
        }
    }

    cout << dist[End] << "\n";
    
    int check = End;
    while(true) {
        if(check == Start) {
            
        }
        tra.push_back(check);
        check = trace[check];
    }

    cout << tra.size() << "\n";

    for(int i = tra.size() - 1; i >= 0; i--) {
        cout << tra[i] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int s, e, c;
        cin >> s >> e >> c;

        vec[s].push_back({e, c});
    }

    cin >> Start >> End;

    dijkstra();
}