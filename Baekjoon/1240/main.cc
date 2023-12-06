#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<pair<int, int>> graph[1001];
bool vis[1001];

int BFS(int start, int end) {
    queue<pair<int, int>>q;
    q.push({start, 0});
    vis[start] = true;
    
    while(!q.empty()) {
        int cur = q.front().first;
        int curCost = q.front().second;
        
        if(cur == end) {
            return curCost;
        }
        
        q.pop();
        
        for(int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            int nCost = graph[cur][i].second;
            
            if(vis[next]) continue;
            vis[next] = true;
            q.push({next, curCost+nCost});
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    
    for(int i = 0; i < n-1; i++) {
        int start, end, cost;
        cin >> start >> end >> cost;
        
        graph[start].push_back({end, cost});
        graph[end].push_back({start, cost});
    }
    
    for(int i = 0; i < m; i++) {
        memset(vis, false, sizeof(vis));
        int start, end;
        cin >> start >> end;
        
        cout << BFS(start, end) << "\n";
    }
}