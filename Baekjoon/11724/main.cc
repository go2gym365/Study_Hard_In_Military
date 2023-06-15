#include<bits/stdc++.h>

using namespace std;

vector<int> vec[1001];
vector<bool> vis(1001, false);

void DFS(int start) {
    vis[start] = true;
    for(int node : vec[start]) {
        if(!vis[node]){
            cout << node << "\n";
            DFS(node);
        }
    }
}

int main() {
    int vertex, edge;
    int cnt = 0;
    cin >> vertex >> edge;

    for(int i = 0; i < edge; i++) {
        int u, v;
        cin >> u >> v;

        vec[v].push_back(u);
        vec[u].push_back(v);
    }

    for(int i = 1; i <= vertex; i++) {
        if(!vis[i]) {
            ++cnt;
            DFS(i);
            cout << "\n";
        }        
    }
    cout << cnt;
}