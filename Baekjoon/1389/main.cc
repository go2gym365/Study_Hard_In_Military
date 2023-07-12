#include<bits/stdc++.h>

using namespace std;

vector<int> vec[101];
vector<bool> vis(101, false);

const int INF = 987654321;
int n, m;
int cnt = 0;

void floyd()

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