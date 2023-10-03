#include<bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> tree[10001];
bool vis[10001];
int deepestNode;
int dia;

void DFS(int cur, int cost) {
    if(dia < cost) {
        dia = cost;
        deepestNode = cur;
    }

    vis[cur] = true;

    for(int i = 0; i < tree[cur].size(); i++) {
        int next = tree[cur][i].first;
        int nCost = tree[cur][i].second;

        if(vis[next]) continue;

        DFS(next, cost + nCost);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;

    for(int i = 0; i < n-1; i++) {
        int start, end, value;
        cin >> start >> end >> value;

        tree[start].push_back({end, value});  
        tree[end].push_back({start, value});    
    }

    DFS(1, 0);
    dia = 0;
    memset(vis, false, sizeof(vis));

    DFS(deepestNode, 0);
    cout << dia;
}