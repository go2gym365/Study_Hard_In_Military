#include<bits/stdc++.h>
using namespace std;

vector<int>v[101];
vector<bool>visited[101];
int cnt = 0;

void DFS(int node)
{
    visited[node] = true;
    for(int k : v[node])
    {
        if(!visited[k])
        {
            DFS(k);
            cnt++;
        }

    }
}

int main()
{
    int n, m;
    for(int i = 0; i < m; i++)
    {
        int vertex, edge;
        cin >> vertex >> edge;
        v[vertex].push_back(edge);
        v[edge].push_back(vertex);
    }

    DFS(1);

    cout << cnt;
}