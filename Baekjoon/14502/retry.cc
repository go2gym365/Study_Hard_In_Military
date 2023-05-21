#include<bits/stdc++.h>
using namespace std;

int N, M, answer = 0;
vector<vector<int>> lab(8, vector<int>(8, 0));

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int BFS()
{
    queue<pair<int, int>> q;
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(lab[i][j] == 2)
                q.push({i, j});
        }
    }
    
    vector<pair<int, int>> virus;

    while(!q.empty())
    {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= M || nx < 0 || ny >= N || ny < 0)
                continue;
            
            if(lab[ny][nx] == 0)
            {
                lab[ny][nx] = 2;
                virus.push_back({ny, nx});
                q.push({ny, nx});
            }
        }
    }

    int ret = 0;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(lab[i][j]==0)
                ret++;
        }
    }

    for(auto v : virus)
    {
        lab[v.first][v.second] = 0;
    }

    return ret;
}

void combination(int cnt)
{
    if(cnt == 3)
    {
        int res = BFS();
        answer = max(res, answer);
        return;
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(lab[i][j] != 0) 
                continue;
            lab[i][j] = 1;
            combination(cnt + 1);
            lab[i][j] = 0;
        }
    }
}

int main()
{
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> lab[i][j];
        }
    }
    combination(0);

    cout << answer;
}