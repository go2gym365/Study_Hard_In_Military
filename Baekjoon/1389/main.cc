#include<bits/stdc++.h>

using namespace std;

vector<int> vec[101];

int n, m;

void BFS()

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