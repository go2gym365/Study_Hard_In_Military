#include<bits/stdc++.h>

using namespace std;

int n, m;
const int INF = 0x3f3f3f3f;

vector<pair<int, int>> input[201];

int dist[201];
int trace[201];

void dijkstra(int start) {
    priority_queue<pair<int, int>> pq;
    
    for(int i = 1; i <= n; i++) {
        if(i == start) {
            dist[i] = 0;
            trace[i] = 0;
        }else {
            dist[i] = INF;
            trace[i] = INF;
        }
    }
    
    pq.push({0, start});
    
    while(!pq.empty()) {
        int curNode = pq.top().second;
        int curCost = -pq.top().first;
        
        pq.pop();
        
        if(dist[curNode] < curCost) continue;
        
        for(int i = 0; i < input[curNode].size(); i++) {
            int nNode = input[curNode][i].first;
            int nCost = curCost + input[curNode][i].second;
            
            if(dist[nNode] > nCost) {
                dist[nNode] = nCost;
                if(trace[curNode] == 0) trace[nNode] = nNode;
                else trace[nNode] = trace[curNode];
                pq.push({-nCost, nNode});
            }
        }
    }
}

void Print(int target) {
    for(int i = 1; i <= n; i++) {
        if(target == i) cout << '-' << ' ';
        else cout << trace[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int s, e, c;
        cin >> s >> e >> c;
        
        input[s].push_back({e, c});
        input[e].push_back({s, c});
    }
    
    for(int i = 1; i <=n; i++) {
        dijkstra(i);
        Print(i);
    }
}