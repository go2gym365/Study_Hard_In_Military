#include <bits/stdc++.h>
using namespace std;
int R, C;
vector<vector<char>> ground(251, vector<char>(251, '0'));
vector<vector<bool>> visited(251, vector<bool>(251, false));
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int W = 0, S = 0;

void BFS(int xx, int yy)
{
    queue<pair<int, int>> q;

    q.push({yy, xx});
    visited[yy][xx] = true;

    int wolf = 0;
    int sheep = 0;

    while(!q.empty())
    {
        int x = q.front().second;
        int y = q.front().first;

        q.pop();        

        if(ground[y][x] == 'v')
            ++wolf;
        else if(ground[y][x] == 'o')
            ++sheep;

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= C || ny < 0 || ny >= R)
                continue;
            if(ground[ny][nx] == '#')
                continue;
            if(visited[ny][nx])
                continue;
            q.push({ny, nx});
            visited[ny][nx] = true;
        }
    }

    if(wolf >= sheep)
        W += wolf;
    else
        S += sheep;
}

int main()
{
    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        string str;
        cin >> str;
        for(int j = 0; j < C; j++)
        {
            ground[i][j] = str[j];
            
        }
    }

    for (int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            if(ground[i][j] != '#' && !visited[i][j])
            {
                BFS(j, i);
            }            
        }
    }
    cout << S << " " << W;
}