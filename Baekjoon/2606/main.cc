#include<bits/stdc++.h>

using namespace std;

vector<int> v[101];
vector<bool> vis(101, false);

int vertex, edge;
int ans = 0;

void DFS(int start) {
    vis[start] = true;
    ans++;

    for(int node : v[start]) {
        if(!vis[node]) { 
            DFS(node);
        }
    }
}

int main() {
    cin >> vertex >> edge;

    for(int i = 0; i < edge; i++) {
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    DFS(1);

    cout << ans - 1;
}