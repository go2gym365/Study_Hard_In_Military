#include<bits/stdc++.h>

using namespace std;

int n;
int dist[100001];
int vis[100001];
int maxCost = 0;
int deepestNode = 0;
vector<pair<int, int>> graph[100001];

void DFS(int cur, int cost) {
    if(cost > maxCost) {
        maxCost = cost;
        deepestNode = cur;
    }

    vis[cur] = true;

    for(int i = 0; i < graph[cur].size(); i++) {
        int next = graph[cur][i].first;
        int ncost = graph[cur][i].second;

        if(vis[next]) continue;

        DFS(next, cost + ncost);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++) {
        int nodeNum;
        cin >> nodeNum;
        int input, value;
        while(true) {
            cin >> input;
            if(input == -1) break;
            cin >> value;
            
            graph[nodeNum].push_back({input, value});
        }
    }

    DFS(1, 0);
    maxCost = 0;
    memset(vis, false, sizeof(vis));

    DFS(deepestNode, 0);

    cout << maxCost;
}