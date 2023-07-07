#include<bits/stdc++.h>

using namespace std;

vector<int> vec[101];
vector<bool> vis(101, false);

int n, m;
int cnt = 0;

void BFS(int start) {
    queue<int> q;
    q.push(1);

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int i = 0; i < vec[cur].size(); i++) {
            int next = vec[cur][i];
            
        }
    }
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int vertex, edge;
        cin >> vertex >> edge;

        vec[vertex].push_back(edge);
        vec[edge].push_back(vertex);
    }

    BFS(1);
}