#include <bits/stdc++.h>
using namespace std;
int R, C;
vector<string>ground;
vector<vector<bool>> visited(251, vector<bool>(251, false));
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int W = 0, S = 0;

void BFS()
{
    queue<pair<int, int>> q;

    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            if(ground[i][j] == '#')
                continue;
            q.push({i, j});
            visited[i][j] == true;
        }
    }

    while(!q.empty())
    {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(ground[ny][nx] == '#')
                continue;
            if(visited[ny][nx])
                continue;
                
        }
    }
}

int main()
{
    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        string str;
        cin >> str;
        ground.push_back(str);
    }


}