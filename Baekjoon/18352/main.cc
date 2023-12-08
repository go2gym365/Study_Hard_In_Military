#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int n, m;
int k, x;

vector<int> input[300001];
int dist[300001];

void dijkstra() {
    dist[x] = 0;
    
    priority_queue<pair<int, int>> pq;
    pq.push({0, x});
    
    while(!pq.empty()) {
        int cur = pq.top().second;
        int cost = -pq.top().first;
        
        pq.pop();
        
        if(dist[cur] < cost) continue;
        
        for(int i = 0; i < input[cur].size(); i++) {
            int next = input[cur][i];
            int nCost = cost + 1;
            
            if(dist[next] > nCost) {
                dist[next] = nCost;
                pq.push({-nCost, next});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(dist, INF, sizeof(dist));
    cin >> n >> m;
    cin >> k >> x;
    
    
    for(int i = 0; i < m; i++) {
        int start, end;
        cin >> start >> end;
        
        input[start].push_back(end);
    }
    
    dijkstra();
    
    bool check = false;
    for(int i = 1; i <= n; i++) {
        if(dist[i] == k) {
            check = true;
            cout << i << "\n";
        }
    }
    if(!check) {
        cout << -1;
    }
}