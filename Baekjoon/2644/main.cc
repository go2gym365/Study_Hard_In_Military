#include<bits/stdc++.h>
using namespace std;

vector<bool> vis(101, false);
vector<int> graph[101];

int n, m, goal1, goal2;
int ans = -1;
void DFS(int cnt, int goal1, int goal2)
{
    vis[goal1] = true;
    if(goal1 == goal2)
    {
        ans = cnt;
        return;
    }

    for(int v : graph[goal1])
    {      
        if(vis[v])
            continue;
        DFS(cnt + 1, v, goal2);
    }


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

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