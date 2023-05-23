#include<bits/stdc++.h>
using namespace std;

int R, C;
int W = 0, S = 0;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};


vector<vector<char>>ground(251, vector<char>(251, '0'));
vector<vector<bool>>vis(251, vector<bool>(251, false));

void BFS(int yy, int xx)
{
    queue<pair<int, int>> q;
    q.push({yy, xx});
    vis[yy][xx] = true;

    int wolf = 0;
    int sheep = 0;

    while(!q.empty())
    {
        int x = q.front().second;
        int y = q.front().first;
        

        q.pop();

        if(ground[y][x] == 'v')
            wolf++;
        else if(ground[y][x] == 'o')
            sheep++;

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= C || ny < 0 || ny >= R)
                continue;
            if(ground[ny][nx] == '#' || vis[ny][nx])
                continue;
            vis[ny][nx] = true;
            q.push({ny, nx});
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

    for(int i = 0; i < R; i++)
    {
        string str;
        cin >> str;

        for(int j = 0; j < C; j++)
        {
            ground[i][j] = str[j];
        }
    }

    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            if(ground[i][j] != '#' && !vis[i][j])
            {
                BFS(i, j);
            }
        }
    }

    cout << S << " " << W;
}