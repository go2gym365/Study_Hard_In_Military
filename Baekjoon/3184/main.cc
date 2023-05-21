#include <bits/stdc++.h>
using namespace std;
int R, C;
vector<vector<char>> ground(251, vector<char>(251, '0'));
vector<vector<bool>> visited(251, vector<bool>(251, false));
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int W = 0, S = 0;

void BFS()
{
    int wolf = 0, sheep = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (ground[i][j] != '#' && !visited[i][j])
            {
                q.push({i, j});
                visited[i][j] = true;
                break;
            }
        }
    }

    while (!q.empty())
    {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= C || nx < 0 || ny >= R || ny < 0)
                continue;
            if (ground[ny][nx] == '#' || visited[ny][nx])
                continue;
            visited[ny][nx] == true;
            if (ground[y][x] == 'v')
                wolf++;
            else if (ground[y][x] == 'o')
                sheep++;
            q.push({ny, nx});
        }
    }
    if (sheep > wolf)
        S += sheep;
    else
        W += wolf;
}

int main()
{
    cin >> R >> C;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> ground[i][j];
        }
    }

    BFS();

    cout << S << ' ' << W;
}