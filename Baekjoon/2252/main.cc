#include<bits/stdc++.h>

using namespace std;

int n, m;

vector<int> graph[32001];
int inDegree[32001];

void topologicalSort() {
    queue<int> q;

    for(int i = 1; i <= n; i++) {
        if(!inDegree[i]) 
            q.push(i);
    }

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        cout << cur << " ";

        for(int i = 0; i < graph[cur].size(); i++) {
            inDegree[graph[cur][i]]--;
            if(!inDegree[graph[cur][i]]) {
                q.push(graph[cur][i]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        inDegree[b]++;
    }

    topologicalSort();
}