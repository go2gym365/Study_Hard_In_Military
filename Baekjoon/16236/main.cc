#include<bits/stdc++.h>

using namespace std;
int N, hunt = 0, sec = 0, size = 2;
vector<vector<int>> space(20, vector<int>(20, 0));
vector<vector<int>> visited(20, vector<int>(20, 0));
int minDes = 987654321;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int minx = 0, miny = 0;

void BFS()
{
    queue<pair<int, int>> q;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(space[i][j] == 9)
            {
                q.push({i, j});
                miny = i;
                minx = j;
                visited[i][j] == 1;
            }    
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

            if(nx >= N || nx < 0 || ny >= N || ny < 0)
                continue;
            if(visited[ny][nx] || space[ny][nx] > size)
                continue;
            if(space[ny][nx] < size && visited[ny][nx] == 0)
            {
                if(space[ny][nx] > 0)
                    space[ny][nx] *= -1;
                if(minDes > visited[miny][minx] + 1)
                    minDes = visited[miny][minx] + 1;
                hunt++;
                sec++;
                q.push({ny, nx});
                visited[miny][minx] += 1;
            }
            else if(space[ny][nx] == 0 || space[ny][nx] >= size)
            {
                q.push({ny, nx});
                visited[miny][minx] += 1;
            }
        }

        if(hunt == size)
            size++;
    }
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> space[i][j];
        }
    }
    BFS();

    return sec;
}