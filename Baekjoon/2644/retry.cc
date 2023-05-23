#include<bits/stdc++.h>
using namespace std;

vector<bool> vis(101, false);
vector<int> graph[101];

int n, m, goal1, goal2;
int ans = -1;

void DFS(int cnt, int dep, int des)
{
    vis[dep] = true;
    if(dep == des)
    {
        ans = cnt;
        return;
    }

    for(int v : graph[dep])
    {
        if(vis[v])
            continue;
        DFS(cnt + 1, v, des);
    }
}

int main()
{
    cin >> n;
    cin >> goal1 >> goal2;
    cin >> m;

    for(int i = 0; i < m; i++)
    {
        int relation1, relation2;
        cin >> relation1 >> relation2;

        graph[relation1].push_back(relation2);
        graph[relation2].push_back(relation1);
    }

    DFS(0, goal1, goal2);

    cout << ans;
}